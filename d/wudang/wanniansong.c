// /d/wudang/wanniansong.c  ������

#include <ansi.h>
inherit ROOM;

int do_jump(string arg);

void create()
{
        set("short",HIG"������"NOR);
        set("long", @LONG
����һ���������ɣ���֦��������ï�ܡ������̸�����ץʯ�ڡ����Ͻ�
���˴��СС���ɹ�������������������֪��ǳ��������֦���㿴��ʯ������
һ����Ȼʯ����
LONG                           
        );
        set("exits", ([
                "enter":__DIR__"lwhole",
        ]));

        set("objects",([
                __DIR__"obj/songguo" : 3,

        ]));

        setup();

}

void init()
{
        add_action("do_jump", ({"tiao", "jump"}));
}

int do_jump(string arg)
{       object me, tmp;
	object *ob;
	int i;

        me=this_player();
        if ( !arg || arg != "down" )
            return notify_fail("��Ҫ��������\n");
        message_vision("$N����һ�գ��¸ҵ�������ȥ��\n"NOR, me);
        if (! present("mao tan", me))
          { 
            message_vision(RED"��---��$Nһ���ҽУ�ֱ�����������ȥ��\n"NOR, me);
            me->die();
//            me->set_temp("last_damage_from","ˤ��������ȵ�");
//            me->die();
		if (tmp = present("corpse", this_object())) {
			ob = deep_inventory(tmp);
			i = sizeof(ob);
			while (i--) if (userp(ob[i])) ob[i]->move(this_object());
			destruct(tmp);
			if (me) tell_room(this_object(), me->name()+"��ʬ�Ƕ��Ҳ����ˡ�\n");
		}
		return 1;
          }
        message_vision(HIY"$N���ڿ��У���æ��ë̺չ������ʱ���˳�����ƮƮ�ػл��㱳�����ȥ��\n"NOR, me);

        me->move(__DIR__"songlin1");

	tell_room(this_object(), me->name() + "���˹�����\n", ({ me }));
        message_vision(HIY"��--��һ����ë̺����֦���ƹ������ϣ�$N����һ��һƨ�ɵ��ڵ��ϡ�\n"NOR, me);
        destruct(present("mao tan", me));

     	write(HIY"�����ڰ�ȫ��½��\n"NOR);
	return 1;
}
