// Room: /d/jingzhou/nanshilu
// netkill /98/8/14/


inherit ROOM;

void create()
{
        set("short", "��ʯ·" );
        set("long", @LONG
����һ������ʯ�̳ɵ�·����Ȼ��Щ������ȴ�ܿ�����������ȥ
���ǳ����ˡ�
LONG
        );
        set("exits", ([
  
  "north" :__DIR__"jznanmen",
  "south" :__DIR__"nanshilu1",
]));

        set("no_clean_up", 0);
        set("outdoors", "jingzhou");

        setup();
        replace_program(ROOM);
}

