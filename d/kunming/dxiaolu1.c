// /d/dali/xiaolu2
// netkill /98/8/14/


inherit ROOM;

void create()
{
        set("short",  "��ʯ·" );
        set("long", @LONG
һ����ʯ�������ʯ�̳ɣ�ƽ̹����������ȥ�����Ե������
�ǣ������������������˶��ô�����·ͨ����

LONG
        );
        set("outdoors", "kunming");

        set("exits", ([
                "east" : __DIR__"dxiaolu", 
                "west"  :__DIR__"changting",
                
                
        ]));

             
        setup();
        replace_program(ROOM);
}
