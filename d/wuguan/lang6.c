//cool 98.4.18

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
���Ǹ����ȣ�����ͨ����Ϣ�ң���������Ʒ�������ﾲ���ĵģ�����
��·��ҲС������ģ��³��ű�����Ϣ������Ϣ���ˡ�
LONG);
	set("exits", ([
	       "north" : __DIR__"woshi1",
	       "south" : __DIR__"wupinfang",
        ]));
	setup();
        replace_program(ROOM);
}

