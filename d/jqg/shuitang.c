// shuitang.c ˮ��
// By River 99.5.25
#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{
           set("short",HIC"ˮ��"NOR);
	   set("long",@LONG
�������֣�ͻȻһ������ӿ������ǰ�ޱ��޼ʵ�ȫ��ˮ�ɻ���ԭ��������
ǳǳ��һƬˮ�������ߣ�������ˮ�ɣ��⻨��ԭ���Ϸ�֮���֪���Ծ�
���ڹ���֮���ɽ�����֡�
LONG
);
           set("outdoors","�����");

           set("resource/water", 1);

	   set("exits",([
              "eastup": __DIR__"shanding",
              "westdown": __DIR__"qsroad",
           ]));

           setup();
}

void init()
{
        add_action("do_drink", "drink");
}

int do_drink(string arg)
{
        int current_water;
        int max_water;
        object me;
        me = this_player();
        current_water = me->query("water");
        max_water = me->query("str")*10 + 100;
        if (current_water < max_water){
            me->set("water", current_water+30);
            message("vision", me->name()+"ſ��Ϫ����������һЩˮ�ȡ�\n",environment(me),({me}));
            write("�����һ�ڴ�ɽ������������Ϫˮ������������ˡ�\n");
        }
        else write("����ô�����ˮ���㲻��������?\n");
        return 1;
}

int get_object(object ob)
{
        if(userp(ob))
        return 1;
        return 0;
}

int valid_leave(object me, string dir,object *obj)
{
       object *inv = deep_inventory(me);
       if (dir == "eastup") {
           write("������һ��Ƭ���֣��������ټ��������ï�ܵ����֣�����֮��ȷʵ������\n");
        obj = filter_array(inv,(:get_object:));        
        if ( random(me->query("kar")) > 12 && ! sizeof(obj))
           write(HIW"\n�㻺�����������д������ŵ�һ���󵭵����㣬�Ǿ����׾�����\n\n"NOR);
            else {
             call_out("kicking", 0, me);
             tell_room(environment(me), me->name()+"�����ߵ�"GRN"����"NOR"�첽�뿪��\n"NOR, ({ me }));
             tell_room(environment(me), me->name()+"��ˮ���첽���˹�����\n"NOR, ({ me }));
             me->look();
             return notify_fail("");
             }
        }
        return ::valid_leave(me, dir);
}
void kicking(object me)
{
me->move(__DIR__"zhulin" + (random(6) + 1));
}
