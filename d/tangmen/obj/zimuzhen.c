// zimuzhen.c
#include <weapon.h>
inherit THROWING;

void create()
{
	set_name("��ĸ����", ({"zimuzhen", "zhen" }));
	if( clonep() )
		set_default_object(__FILE__);
	else {
                set("long", "����һ��ϸ����˿�����롣\n");
		set("unit", "Щ");
                set("base_value", 1);
		set("material", "steel");
                set("base_unit", "��");
		set("base_weight", 10); 
	}	
        set_amount(999);
        init_throwing(800);
        setup();
}

void init()
{
        add_action("do_wield", "wield");
	add_action("do_unwield", "unwield");
}
// 30
int do_wield(string arg)

{  object victim; int damage_bonus; int factor;
       object me=this_player();

        object ob;
        string str;
	int i, count;

// 40
        if (!id(arg))   return notify_fail("��Ҫװ��ʲô��\n");


	if( !objectp(ob = present(arg, me)) )
		return notify_fail("������û������������\n");

	if( ob->query("equipped") )
		return notify_fail("���Ѿ�װ�����ˡ�\n");

// 50
	if( ob->wield() ) {
              if( !stringp(str = ob->query("wield_msg")) )
			str = "$Nװ��$n��������\n";
              message_vision(str, me, ob);me->set_temp("marks/��ĸ��",1);
 
//	}

              return 1;
	}

        else
                return 0;
}
int do_unwield(string arg)

{  object victim; int damage_bonus; int factor;
       object me=this_player();

        object ob;
        string str;
	int i, count;

// 40
        if (!id(arg))   return notify_fail("��Ҫ����ʲô��\n");


	if( !objectp(ob = present(arg, me)) )
		return notify_fail("������û������������\n");

	if( ob->query("equipped") )
		return notify_fail("���Ѿ������ˡ�\n");

// 50
	if( ob->unwield() ) {
              if( !stringp(str = ob->query("unwield_msg")) )
			str = "$N�������е�$n��\n";
              message_vision(str, me, ob);me->delete_temp("marks/��ĸ��");

//	}

              return 1;
	}

        else
                return 0;
}
