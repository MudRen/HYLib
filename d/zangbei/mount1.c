 inherit ROOM;
#include <ansi.h> 
void create() 
{
        set("short", "�����");
        set("long", @LONG
���壬�����˳�֮Ϊ�������ա���ԶԶ��ȥ����һ������ض�����������
���ϣ�ɽ����Χ�Ƿ����������СС����ʮ������ǧ�˰�̬��εΪ׳�ۡ���������
ɽ���¾��������ĳ���º����ĸ�
LONG
        );
        set("exits", ([ 
                "south" : __DIR__"nianqing",
                "northwest":  __DIR__"zhayi",
        ]));
        set("objects", ([
        ]) );
        set("outdoors", "zangbei");
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup(); 
} 
