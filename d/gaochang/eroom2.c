
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
    set("valid_startroom", 1);
	set("exits", ([
		"south" : __DIR__"eroom1",
		"north" : __DIR__"eroom3",
	]));
	setup();
	replace_program(ROOM);
}



