
inherit ROOM;



void create()
{
	set("short", "�����");
	set("long", @LONG
ÿһ�䷿�д󶼹��з���żȻ�ڱ��ϼ����������ģ�
д���ǡ��߲���������������̩�������������ʮ���꡹�ȵ���������һ��
�����й��Ķ��Ǻ�����������д���ǡ������ʥ��ʦ����λ�������Ҹ�����
ʮ�ˣ�д�����ջء�������·�������ӹ����������ġ��������š������֡�
LONG
	);

	set("exits", ([
		"south" : __DIR__"wroom1",
		"north" : __DIR__"wroom3",
//	]));

//	set("objects",([
//		CLASS_D("shaolin") + "/cheng-guan" : 1,
	]));
	setup();
	replace_program(ROOM);
}



