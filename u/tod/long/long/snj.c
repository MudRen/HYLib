//shunu jian

#include <weapon.h>
#include <ansi.h>

inherit SWORD;

void create()
{
        set_name( RED"��Ů��"NOR,({ "shunu sword", "shunu" }) );
        set_weight(8000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 5000000);
                set("material", "steel");
                set("long", BLU"�˽��ںڵĽ���û�����󣬾���һ�κ�ľ��������Ů���֡�����ӽ�һ��
���̣�ȫ�޶��¡�˫�����������������ֻ�Ǵ˽����޼�ͷ�����޽��棬Բͷ�۱ߣ������߷���һ��������ľ�ޡ�\n"NOR);
                set("wield_msg", RED "$N��������Ҿ�����������Ů����ֻ����ƮƮ��������������һ������
��Ȼ���ˣ�����Ī�ɺ��ӡ�$N�ٽ���̣��������غ��֣�������㡣\n"NOR);
                set("unwield_msg", RED "$N�������ƣ�����Ů��������ؽ��ʣ�������Ȼ��\n" NOR);
                set("unequip_msg", BLU "$N�������һ���ڹ�Ծ����У�������δ��������ƮƮ�����ڹ���ʧ��
������Ȼ���ʡ�\n" NOR);
        }
        init_sword(600);
        setup();
}
