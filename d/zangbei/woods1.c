 inherit ROOM;
#include <ansi.h> 
void create() 
{
        set("short", "��������");
        set("long", @LONG
·�Եİ�����������ʮ�����������������֣�һ���Ű�Ȼ��ͦ������ͬ
���ڵ�ʿ��������ͨ�����ɰѸߣ����Ǽ����˹��Ƶģ���ֱ���ϣ�������֦����֦
Ҳ�Ǳ�ֱ���ϣ����ҽ�����£��Ҳ���Ǿ����˹��Ƶģ���Ϊһ�������޺�б�ݳ���
LONG
        );
        set("exits", ([ 
                "north" : __DIR__"wild4",
                "south" : __DIR__"woods2",
        ]));
        set("objects", ([
        ]) );
        set("outdoors", "zangbei");
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup(); 
}     
