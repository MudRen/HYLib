//Room:/d/lingshedao/haitan1.//Creat by Yjss on Sep.1999
inherit ROOM;
void create()
{
        set("short", "��̲");
        set("long", @LONG
����һ����ľ�д�Ĵ󵺣��������ͦ�Σ������ź�
������ɽ.��·����һ����Ƶ�ʯ��(shibei).
LONG );
        set("outdoors", "lingshedao");
        set("exits", ([
                "northeast"    : __DIR__"lsroad1",
                "south"    : "/d/binghuo/lingshedao",	
        ]));
        set("item_desc",([
                "shibei" : "
                   ��
                   ��
                   ��\n\n",
        ]));   
        set("no_clean_up",0);             
        setup();
        replace_program(ROOM);
}
