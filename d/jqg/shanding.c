// shanding.c ɽ��
// By River 99.5.25
#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{
         set("short",YEL"ɽ��ƽ��"NOR);
	 set("long",@LONG
ɽ�����ܲ�ľ������Σ������ƽ���һ·�����Ƿ����ʤ���˴����Ǹ���
��������֮�أ��Ų����У�ֻ��·���ɺ���������¹��Ⱥ������С�ã����Ǽ�
�˲���������һ��ɽ·��֪ͨ���δ���������һ��Ƭ���֡�
LONG
);
          set("outdoors","�����"); 
          set("exits",([
             "southdown": __DIR__"shanjing1",
             "west": __DIR__"xshiwu",
             "east": __DIR__"shanlu4",
             "northdown": __DIR__"shuitang"
          ]));

          setup();
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
       if (dir == "northdown") {
           write("������һ��Ƭ���֣��������ټ��������ï�ܵ����֣�����֮��ȷʵ������\n");
        obj = filter_array(inv,(:get_object:));        
        if ( random(me->query("kar")) > 12 && ! sizeof(obj))
           write(HIW"\n�㻺�����������д������ŵ�һ���󵭵����㣬�Ǿ����׾�����\n\n"NOR);
            else {
             tell_room(environment(me), me->name()+"�����ߵ�"GRN"����"NOR"�첽�뿪��\n"NOR, ({ me }));
             me->move(__DIR__"zhulin" + (random(6) + 1));
             tell_room(environment(me), me->name()+"��ɽ��ƽ�ؿ첽���˹�����\n"NOR, ({ me }));
             me->look();
             return notify_fail("");
             }
        }
        return ::valid_leave(me, dir);
}
