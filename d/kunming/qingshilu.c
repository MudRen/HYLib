// /d/kunming/qingshilu
// netkill /98/8/14/


inherit ROOM;

void create()
{
        set("short",  "��ʯ·" );
        set("long", @LONG
����ʯ�֣��͵��������Ĺٵ�����ʯ�̳ɣ�ƽ̹��������ȥ��Զ
���������ˡ�
LONG
        );
        set("outdoors", "kunming");

        set("exits", ([
                "west" : __DIR__"qingshilu1", 
                "east" :  "/d/wudujiao/xiao3", 	
                "northeast"  :__DIR__"shilin2",
                
                
        ]));

             
        setup();
        replace_program(ROOM);
}
