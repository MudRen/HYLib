 inherit ROOM;
#include <ansi.h> 
void create() 
{
        set("short", "��������");
        set("long", @LONG
�ޱ��޼ʵĻ�ԭ��һ�Ű�Ȼ���������ڱ��ƵĘ�ľ������Ũ�ܣ��������
���İ������֡��Pֱ��Ǭ���Pֱ��֦��Ǭͨ�����ɰѸߣ����Ǽ����˹��Ƶģ�һ��
�ԃȣ��^�o��֦��Ѿ֦һ�����ϣ����Ҿo�o���n��Ҳ���Ǽ����˹��Ƶģ��ɞ�һ����
�^�o�Mб�ݳ���
LONG
        );
        set("exits", ([ 
                "northeast" : __DIR__"wild2",
                "west" : __DIR__"woods2",
                "southeast":    __DIR__"forest1",
        ]));
        set("objects", ([
        ]) );
        set("outdoors", "biancheng");
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
}       
