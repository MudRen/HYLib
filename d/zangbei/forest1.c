 inherit ROOM;
#include <ansi.h> 
void create() 
{
        set("short", "����");
        set("long", @LONG
���������ߣ���һ���ߴ�ï�ܵ�ɭ�֣�������������ȴ��ļž������ţ���Ŀ
���ǽ�Ҷ�Ϳݲݡ�Ұ�޴�������ţ��е����Ļţ�������������޷����ܣ��·�
��ɭ�ֵĽ��ɫ����ɪ�У���һ�������������Ȼ�����ڴ��������� 
LONG
        );
        set("exits", ([ 
                "west" : __DIR__"woods2",
                "east": __DIR__"cave",
                "southeast": __DIR__"forest2",
        ]));
        set("objects", ([
        ]) );
        set("item_desc",([
                "grass": "���ϵĿ�Ҷ���������Ҳ��֪�Ѿ����˶������ˡ�\n",
                "�ݲ�": "���ϵĿ�Ҷ���������Ҳ��֪�Ѿ����˶������ˡ�\n",
                "��Ҷ": "���ϵĿ�Ҷ���������Ҳ��֪�Ѿ����˶������ˡ�\n",
        
        ]) );
        set("outdoors", "zangbei");
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup();
}  
void init() {
        add_action("do_listen","listen");
}  
int do_listen() {
        object me;
        me=this_player();
        tell_object(me,"���������������������ء�������\n");
        tell_object(me,"��ֻ��֪���Ķ����Ȼ������󴩹����굽������������ﲻ���ˡ�\n");
        return 1;
}   
