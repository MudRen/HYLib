//Cracked by Roath
// incense.c ���
// By Marz 11/11/96

inherit ITEM;

void wear(int);

int worn;

void create()
{
	set_name("���",({"incense"}));
	set_weight(50);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "����һ֦�����������𣬻�������֦��������\n");
		set("unit", "֦");
		set("value", 10000);
		if (this_player()->query("id") != "xqin")
		{
		set("no_drop", 1);
		set("no_get", 1);
		}
    	}
	
	setup();
}

void init()
{
	worn = 0;
	call_out("wear", 120, 1); 
}



void wear(int phase)
{
	worn = phase;
	switch(phase) {
	case 1:
		set("long", "����һ֦�����õ���𣬵��Ѿ���ʼʧȥ��ζ�ˡ�\n");
		call_out("wear", 120, phase+1); 
		break;
	case 2:
		set("long", "����һ֦���˺ܾõ���𣬼�����ȫʧȥ�����ˡ�\n");
		call_out("wear", 120, phase+1); 
		break;
	case 3:
		destruct(this_object());
		break;
	}	
}

// End of File 
