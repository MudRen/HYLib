 inherit ROOM;
#include <ansi.h> 
void create()
{
        set("short", "��������");
        set("long", @LONG
���������������������ˣ�������ߡ����ɣ�������Ѿ֦�����εĴ�Ҷ����ס
�˰����ա������ŵ������ɹ������㣬������Χ������ģ�ʲôҲ�����塣��Ҷ
���ƺ��м������ѣ�����ߴߴ�����Ľ�������������̫Զ����ôҲ��������
LONG
        );
        set("exits", ([ 
                "down" : __DIR__"pine1",
        ])); 
        set("item_desc", ([
                "����": "��Ҷ���ƺ��м������ѣ�����ߴߴ�����Ľ�����Ҳ���������������ȥ��jumpto��������\n",
                "nest": "��Ҷ���ƺ��м������ѣ�����ߴߴ�����Ľ�����Ҳ���������������ȥ��jumpto��������\n",
        ]));
        set("in_tree",1);
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup();
        
} 
void init() {
        add_action("do_jump","jumpto");
}  
int do_jump(string arg){
        object me, room,item;
        
        me=this_player();
        
        if (!arg || (arg != "nest" && arg!="����") )
                return notify_fail("��Ҫ���Ķ�����\n");
        
        message_vision("\n$N��һ���������������ѵķ�������һԾ��\n",me);
        
        room = find_object(__DIR__"temple5");
        if (!objectp(room)) room= load_object(__DIR__"temple5");
   
        if (me->query_skill("move",1)<=100) {
                message_vision("$Nһ�Ųȿգ�˫������к���ץ�˼��£�һ������������ȥ��\n\n",me);
                message("vision","ֻ����ͨһ�������ϵ���һ��������\n",room);
                me->move(room);
                me->unconcious();
                return 1;
        }
        
        if (me->query_temp("zangbei/����")) {
                tell_object(me,WHT"�㳯���Ǹ�����ע�ӹ��ĵط�Ծȥ����������֦��һ��һԾ��\n"NOR);
                tell_object(me,WHT"��žһ������֦���ˣ����æ֮��������������һ����ץ��һ��ӲӲ�Ķ�����
�Ͻ��������\n"NOR);
                item = new(__DIR__"obj/item");
                item->move(me);
        }
        
        message_vision("$N������������֮����ֱͨͨ����������ȥ��\n\n",me);
        message("vision","ֻ����ͨһ������������һ��������\n",room);
        me->move(room);
        return 1;
} 
