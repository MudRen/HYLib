#include <armor.h>
#include <ansi.h>
inherit WAIST;

void create()
{
        set_name(HIM "�־�" NOR, ({ "kerchief", "shou juan", "juan" }) );
        set_weight(5);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
               set("long", "����һ��˿���־ɢ���ŵ������������������������֡�С���ӡ���\n");
                set("value", 100000);
                set("armor_prop/armor", 100);
                set("armor_prop/personality", 3);

        }

}


void init()
{
        add_action("quit", "q1");
        add_action("do_bian", "bian");
}

int quit()
{
//      message("shout",HIR"������С�����������������㣬�������ѣ�����Ը�����۾�����ƾ������˯���ѣ�������ҵ�������\n"NOR,users());
return 1;
}

int do_bian(string arg)
{
        object who;
        if (!arg)

               return notify_fail("�����ʲô��\n");
       if (arg == "human" || arg == "ren") {
if (!this_player()->query_temp("fox")) return notify_fail("����ͻ��������ˣ�\n");
                this_player()->delete_temp("apply/name");
                this_player()->delete_temp("apply/long");
this_player()->delete_temp("fox");
message_vision(HIY"һ���������$N���ϵ���ë���ˣ������һ��������ݣ�üĿ����Щ΢���������\n"NOR, this_player());
                return 1;
        }
       if (arg == "fox" || arg == "huli")
{if (this_player()->query_temp("fox")) return notify_fail("��ԭ�����Ǻ���ѽ��\n");
        message_vision(HIR"$N�ƺ���Щ���Ծ�����ԭ�������ϡ��ֱ��Ͼ�����һ��ë�����ν�����С��������һֻ���ꡣ\n"NOR, this_player());
            this_player()->set_temp("apply/name", ({"��β����"}));
            this_player()->set_temp("apply/long", ({"һֻ�о���β�͵ĺ��ꡣ\n"}));
this_player()->set_temp("fox",1);
        return 1;
}
}

