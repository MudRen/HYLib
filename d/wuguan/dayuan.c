//cool 98.4.18
inherit ROOM;

void create()
{
	set("short", "��ݴ�Ժ");
	set("long", @LONG
���Ǹ���Ժ�ӣ��������߶������䳡��������������ϰ��ǿ������
�ܳ����Һ��ģ��㿴����ʱ�п��Ŷ����ģ�����ˮ�ĴҴҶ�����
LONG);
	set("exits", ([
	        "south" : __DIR__"guanmen",
		"north" : __DIR__"dayuan2",
                "east" : __DIR__"lang2",
		"west" : __DIR__"lang1",
	]));
        set("no_fight",1);
        set("no_sleep_room", 1);  
        set("valid_startroom", 1);
	setup();
//        "/clone/board/wuguan_b.c"->foo();
        replace_program(ROOM);
}


