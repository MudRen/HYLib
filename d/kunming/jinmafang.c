// /d/kunming/jinmafang
// netkill /98/8/14/


inherit ROOM;

void create()
{
        set("short",  "������" );
        set("long", @LONG
������ʤ֮һ�������ʣ���˵��ÿ���һ�죬��Ӱ�Ӻͱ̼���
��Ӱ�ӽ����ӡ����Ϊ��̽���,ΡΡ��ۡ�
LONG
        );
        set("outdoors", "kunming");

        set("exits", ([
                "west" : __DIR__"xiaoximen", 
                "east"  :__DIR__"jinrilou",                
        ]));

//	set("objects", ([
//		"wizhome/sharkhome/npc/bukuai" : 1,		
//	]));

        setup();
        replace_program(ROOM);
}
