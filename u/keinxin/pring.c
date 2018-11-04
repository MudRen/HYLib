//Cracked by Kafei
// pring.c �׽��ָ

#include <armor.h>
#include <ansi.h>

inherit FINGER;

void create()
{
        set_name(HIW"�׽����"NOR, ({ "platinum ring", "ring" }));
        set("weight", 400);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 9900);
                set("material", "platinum");
                set("no_sell", 1);
                set("armor_prop/armor", 1);
        }
        setup();
}       

void init()
{
        object me = this_player();
                
        // married but not wearing ring, must be just married or login
        if( me->is_married() && !me->query_temp("ring_worn") ) {
                if( me->query("gender") == "Ů��" )
                        set("long", "��ָ�Ͽ��ż���С�֣���ǿ������  "
                                + me->query("spouse/name") + "��\n");
                else
                        set("long", "��ָ�Ͽ��ż���С�֣��������  "
                                + me->query("spouse/name") + "��\n");
                set("no_drop", 1);
                set("no_get", 1);       
                wear();
                me->set_temp("ring_worn", this_object());
                add_action("disable_remove", "remove");
                remove_action("do_exchange", "exchange");
                remove_action("do_exchange", "huan");
        } else {
                set("long", "һö�������İ׽���䣬����һ��"+HIW"De Beers��ʯ"NOR+"���貹�â�����ŷ���֮���쳤�ؾá�\n");
//              set("no_drop", 0);
//              set("no_get", 0);       
                add_action("do_exchange", "exchange");
                add_action("do_exchange", "huan");
                remove_action("disable_remove", "remove");
        }       
                
        return;
}

int disable_remove(string arg)
{
        if (!id(arg)) return notify_fail("��Ҫ�ѵ�ʲô��\n");
        
        write("��������ȡ��������\n");
        return 1;
}        

int do_exchange(string arg)
{
        string name, id;
        object me, who, so, ob2;
        
        me = this_player();

        if( !arg
        || sscanf(arg, "%s %s", name, id) != 2
        || id != "platinum ring" && id != "ring"
        || !objectp(who = present(name, environment(me))) )
                return notify_fail("��Ҫ��˭������ָ? \n");

	if( objectp(me->query_temp("armor/finger")) )
		return notify_fail("�����ϻ����Ž�ָ�ء�\n");

	if( objectp(who->query_temp("armor/finger")) )
		return notify_fail(who->name() +"���ϻ����Ž�ָ�ء�\n");

        if( me->query_temp("marriage/ring") != who
        || who->query_temp("marriage/ring") != me )
                return notify_fail("�㻹�����Һû���ָ���˰ɡ�\n");
                
        if( !objectp(so = present("platinum ring", who)) )
                return notify_fail("��ϧ�Է�û�н�ָ���Ժ��㽻����\n");

        if( !living(who) ) 
                return notify_fail("������Ȱ�" + who->name() + "Ū�ѡ�\n");
                        
        if( me->query("gender") == "Ů��" ) {           
                message_vision(HIM "$N��������һö�׽������������$n������ָ�ϡ�\n" NOR,
                        who, me);
                message_vision(HIM "$N�������棬����һö�׽��������$n������ָ�ϡ�\n" NOR,
                        me, who);
        } else {
                message_vision(HIM "$N��������һö�׽������������$n������ָ�ϡ�\n" NOR,
                        me, who);
                message_vision(HIM "$N�������棬����һö�׽��������$n������ָ�ϡ�\n" NOR,
                        who, me);
        }
                        
        me->delete_temp("marriage/ring");
        who->delete_temp("marriage/ring");
//        MARRY_D->setup_marriage(me, who, this_object(), so);

// Newly weds can get free rides to different places. xbc 04/16/97

        me->set_temp("marriage/newly_wed", 1);
        who->set_temp("marriage/newly_wed", 1);

//        ob2 = new("clone/obj/carm.c");
//        ob2->move("/d/city/beidajie2");
        
        return 1;
}
