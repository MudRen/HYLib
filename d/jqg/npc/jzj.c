// junzi jian ���ӽ�

#include <weapon.h>
#include <ansi.h>

inherit SWORD;

void create()
{
        set_name( BLU"���ӽ�"NOR,({ "junzi jian", "junzi" }) );
        set_weight(8000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 25000);
                set("material", "steel");
                set("long", BLU"�˽��ںڵĽ���û�����󣬾���һ�κ�ľ�����ž��Ӷ��֡�����Ů��һ��
���̣�ȫ�޶��¡�˫�����������������ֻ�Ǵ˽����޼�ͷ�����޽��棬Բͷ
�۱ߣ������߷���һ��������ľ�ޡ�\n"NOR);
                set("wield_msg", HIY "$N����������ӽ���ֻ����ƮƮ��������������һ��������Ȼ���ˣ�����
Ī�ɺ��ӡ�$N�ٽ���̣��������غ��֣�������㡣\n"NOR);
                set("unwield_msg", BLU "$N�������ƣ������ӽ�������ؽ��ʣ��������ȷǷ���\n" NOR);
                set("unequip_msg", BLU "$N�������һ���ڹ�Ծ����У�������δ��������ƮƮ�����ڹ���ʧ��
������Ȼ���ʡ�\n" NOR);
        }
        init_sword(450);
        setup();
}
