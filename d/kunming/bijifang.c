// /d/kunming/bijifang
// netkill /98/8/14/


inherit ROOM;

void create()
{
        set("short",  "�̼���" );
        set("long", @LONG
������ʤ֮һ���̼��ʣ���˵��ÿ���һ�죬��Ӱ�Ӻͽ�����
��Ӱ�ӽ����ӡ����Ϊ��̽���,ΡΡ��ۡ�
LONG
        );
        set("outdoors", "kunming");

        set("exits", ([
                "west" : __DIR__"jinrilou", 
                "east"  :__DIR__"dongmen",
                
                
        ]));

             
        setup();
        replace_program(ROOM);
}
