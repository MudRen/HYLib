 inherit ROOM;
#include <ansi.h> 
void create() 
{
        set("short", "�ӹ�");
        set("long", @LONG
��Խ���ɽçç�ԲԵ�ԭʼɭ�֣�ӭ������խ�վ����������ٵĺӹȡ�һ��С
·����������������һƬԭʼɭ�֣�ǰ���Ƿ�̵伮���ᵽ�ĵ����ȣ���˵�Ǿ�ס
��ѩɽ�ϵ������ǳ��ζ�ħ�ĵط���ÿ���ºڷ��ʱ��ɱ���ߵĺ����뱻ɱ�ߵİ�
���������˺�ë������
LONG
        );
        set("exits", ([ 
                "northeast" : __DIR__"hellvalley3",
                "westup":  __DIR__"hellvalley1",
        ]));
        set("objects", ([
        ]) );
        set("outdoors", "zangbei");
            set("coor/x",-1050);
        set("coor/y",2100);
        set("coor/z",0);
        setup(); 
}    
