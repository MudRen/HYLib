// By Batman @ Freedom Studio 2001/6/6

#include <weapon.h>
#include <ansi.h>

inherit SWORD;

void create()
{
        set_name(HIC"����"NOR, ({ "skysword","sword","jian" }) );
        set_weight(7000);
        if( clonep() )
                set_default_object(__FILE__);
        else
        {
                set("unit", "��");
                set("long", "����һ�ѹŽ��������ϵĻ��Ƴ�����״�������Ϻ�Ȼ����"HIC"�����塹"NOR"��\n����һ����������"MAG"��������"NOR"��һ�ԡ�\n");
                set("value", 7000);
                set("material", "steel");
                set("wield_msg", HIC"ͻȻ�䣬������Ʋʾ�ɢ��$N����ġ����塹��Ȼ���ʡ�\n����ɢ���Ĺ�âʹ�����������һ�ɺ�����\n"NOR);
                set("unwield_msg", HIC"$N���˸����ƣ������еġ����塹�����ع��뽣�ʡ�\n"NOR);
                set("����",1);

                set("no_pawn", 1);
                set("combine_id", "groundsword");
                set("combine_name", MAG"����"NOR);
               set("combine_object", "/u/tod/obj/qksword.c");
                set("combine_msg", "����һ��ͻȻ��ر�ɫ��һ�������˫�������");
        }
        init_sword(80);
        setup();
}

