this pointer:

防止空指针指向对应的成员变量，应该采用
		if (this == NULL)
		{
			return; 
		}

		防止继续往下运行