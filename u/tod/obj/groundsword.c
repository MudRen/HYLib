// By Batman @ Freedom Studio 2001/6/6

#include <weapon.h>
#include <ansi.h>

inherit SWORD;

void create()
{
        set_name(MAG"����"NOR, ({ "groundsword","sword","jian" }) );
        set_weight(7000);
        if( clonep() )
                set_default_object(__FILE__);
        else
        {
                set("unit", "��");
                set("long", "����һ�ѹŽ��������ϵĻ��Ƴɷ���״�������Ϻ�Ȼ����"MAG"��������"NOR"��\n����һ����������"HIC"�����塹"NOR"��һ�ԡ�\n");
                set("value", 7000);
                set("material", "steel");
                set("wield_msg", MAG"ͻȻ�䣬���ܶ��ž���������$N����ġ���������Ȼ���ʡ�\n����ɢ�����������������ЩƮȻ��\n"NOR);
                set("unwield_msg", MAG"$N���˸����ƣ������еġ������������ع��뽣�ʡ�\n"NOR);
                set("����",1);

                set("no_pawn", 1);
                set("combine_id", "skysword");
                set("combine_name", HIC"����"NOR);
                set("combine_object", "/u/tod/obj/qksword.c");
                set("combine_msg", "����һ��ͻȻ��ر�ɫ��һ�������˫�������");
        }
        init_sword(80);
        setup();
}

