// /d/kunming/qingshilu1
// netkill /98/8/14/


inherit ROOM;

void create()
{
        set("short",  "��ʯ·" );
        set("long", @LONG
һ����ʯ�������ʯ�̳ɣ�ƽ̹������ԶԶ�Ŀ��Կ��������ˡ�
LONG
        );
        set("outdoors", "kunming");

        set("exits", ([
                "west" : __DIR__"qingshilu2", 
                "east"  :__DIR__"qingshilu",
                
                
        ]));

             
        setup();
        replace_program(ROOM);
}
