// Room: /d/cangzhou/gongdi.c

inherit ROOM;
void create()
{
        set("short", "����");
        set("long", @LONG
����һ�����ڽ����еĹ��ء���˵�����ε�֪����լԺ��������������æ
æµµ���������֡�
LONG );
        set("exits", ([
        	"west" : __DIR__"beijie2",
	]));
	set("outdoors", "����");

	setup();
}