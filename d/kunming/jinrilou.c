// /d/kunming/jinrilou
// netkill /98/8/14/


inherit ROOM;

void create()
{
        set("short",  "���չ�¥" );
        set("long", @LONG
����¥�ش����������ģ������������˶�������ͨ������¥��
��һ���ӣ�������ƽ��������һ���˺���ȥ��������ǽ����ʣ�
�ϱ����ַǷ�����������������������
LONG
        );
        set("outdoors", "kunming");

        set("exits", ([
                "west" : __DIR__"jinmafang", 
                "east"  :__DIR__"bijifang",
                "south" :__DIR__"nandajie1",
                "north" :__DIR__"beidajie",
                "up"    :__DIR__"zhonglou",                           
        ]));

        setup();
        replace_program(ROOM);
}
