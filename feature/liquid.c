// liquid.c

string extra_long()
{
	int amount, max;
	string str;
        object ob = this_object();
        
	if( amount = ob->query("liquid/remaining") ) {
		max = ob->query("max_liquid");
		if( amount == max )
			str = "����װ����" + ob->query("liquid/name") + "��\n";
		else if( amount > max/2 )
			str = "����װ���ߡ��˷�����" + ob->query("liquid/name") + "��\n";
		else if( amount >= max/3 )
			str = "����װ���塢��������" + ob->query("liquid/name") + "��\n";
		else if( amount < max/2 )
			str = "����װ�������" + ob->query("liquid/name") + "��\n";
		return str;
	}
	else return 0;
}

