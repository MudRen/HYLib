// /d/kunming/qingshilu2
// netkill /98/8/14/


inherit ROOM;

void create()
{
        set("short",  "��ʯ·" );
        set("long", @LONG
һ����ʯ�������ʯ�̳ɣ�ƽ̹������̧ͷһ����ǰ��ĳ��������ɼ���
LONG
        );
        set("outdoors", "kunming");

        set("exits", ([
                "west" : __DIR__"dongmen", 
                "east"  :__DIR__"qingshilu1",
                
                
        ]));

             
        setup();
        replace_program(ROOM);
}
