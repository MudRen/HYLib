// By River@SJ 2001/9  

inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
������һ����������Ĵ�����ϡ��������������������ӵ����̣����Ŵ�
��������Ͼ��Ͽ��������������������ǳ����֡���ʱ����������������
�߷ɳ۶���������һ·��������·��������������������֡�
LONG
        );
	set("outdoors", "���ݳ�");
	set("group", 1);

	set("exits", ([ 
		"southwest" : "/d/cangzhou/eroad2",
		"northeast" : "/d/cangzhou/eroad4",
	]));

	setup();
}
