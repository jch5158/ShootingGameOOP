#pragma once

template <typename T>
class CList
{
private:

	struct Node {
		T data;
		Node* prev;
		Node* next;

		// ����ü ������
		Node(T data = NULL) {
			this->data = data;
			next = nullptr;
			prev = nullptr;
		}
	};

public:
	class Iterator {

	private:
		Node* node;

	public:

		// CList�� pivate�� ������ �� �ֵ���
		friend class CList;

		// ����
		Iterator(Node* node = nullptr) {
			this->node = node;
		}


		Iterator NextIter() {

			Iterator iter(this->node->next);

			return iter;
		}


		void operator=(Iterator iter) {
			this->node = iter.node;
		}


		// ���� ++ ������ �����ε�
		const Iterator operator++(int) {

			//��忡 �ؽ�Ʈ�� ���� ��
			if (node->next != nullptr)
			{
				const Iterator iterator(this->node);

				this->node = node->next;

				return iterator;
			}

			// ������ nullptr�� ����Ű�� ��带 return�Ѵ�.
			return Iterator();
		}

		// ���� ++ ������ �����ε�
		Iterator operator++() {
			//��忡 �ؽ�Ʈ�� ���� ��
			if (node->next != nullptr) {
				this->node = node->next;

				return this->node;
			}
			return Iterator();
		}

		const Iterator operator--(int) {

			//��忡 prev ���� ��
			if (node->prev != nullptr)
			{
				const Iterator iterator(this->node);

				this->node = node->prev;

				return iterator;
			}

			// ������ nullptr�� ����Ű�� ��带 return�Ѵ�.
			return Iterator();
		} 


		// ���� -- ������ �����ε�
		Iterator operator--() {
			//��忡 prev ���� ��
			if (node->prev != nullptr) {
				this->node = node->prev;

				return this->node;
			}

			return Iterator();
		}

		T operator*() const {
			return this->node->data;
		}

		T operator->() const {
			return this->node->data;
		}

		bool operator==(const Iterator& iter) const {

			return this->node->data == iter.node->data;
		}

		bool operator!=(const Iterator& iter) const {
			return !(this->node->data == iter.node->data);
		}
		// dddd�� �з��־���..

	};

private:

	Node* head;
	Node* tail;

public:

	int listLength = 0;

	// CList ������
	CList() {

		head = new Node();
		tail = new Node();

		head->next = tail;
		tail->prev = head;

		tail->next = nullptr;
		head->prev = nullptr;
	}

	//  CList �Ҹ���
	~CList() {
		Node* prev = nullptr;

		while (head != nullptr) {
			prev = head;

			head = head->next;

			delete prev;
		}
	}

	// ������� �ڿ� �߰��ϴ� �Լ�
	void PushBack(T data) {

		Node* node = new Node(data);

		InputNode(node, tail);


		//���� üũ�ϴ� ��������Դϴ�.
		this->listLength += 1;
	}

	// ������ ������ �߰�
	void PushFront(T data) {

		Node* node = new Node(data);

		InputNode(node, head->next);

		//���� üũ�ϴ� ��������Դϴ�.
		this->listLength += 1;
	}

	// Ư�� ��� �ڿ� �߰�
	void insert(Iterator iter, T data) {

		Node* node = new Node(data);

		InputNode(node, iter.node);
	}

	//���۰� ��ȯ
	Iterator begin() {

		//Iterator iterator(head->next);

		return Iterator(head->next);
	}

	// ���� ��ȯ
	Iterator end() {

		Iterator iterator(tail);
		return iterator;
	}

	Iterator erase(Iterator iter) {

		Iterator iterBuffer = iter;

		iterBuffer.node->prev->next = iterBuffer.node->next;

		iterBuffer.node->next->prev = iterBuffer.node->prev;

		Iterator iterator(iterBuffer.node->next);

		delete iterBuffer.node;

		//���� üũ�ϴ� ��������Դϴ�.
		this->listLength -= 1;

		return iterator;
	}

	// Ư�� ��带 ����� ���̴�.
	bool Remove(T data) {

		Iterator iterE = this->end();

		for (Iterator iter = begin(); iter != iterE; ++iter) {

			if (iter.node->data == data) {

				erase(iter);

				
				return true;
			}

		}

		return false;
	}



private:

	//�Ű����� 1 : �����߰��� ��� , �Ű����� 2 : Ư�����	
	//Ư�� ��ġ�� ���ڿ� ���ο� ��带 �߰��Ѵ�.
	void InputNode(Node* now, Node* pos) {

		now->prev = pos->prev;
		now->next = pos;

		pos->prev->next = now;
		pos->prev = now;
	}

};

