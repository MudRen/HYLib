// turou.c ���õ���
inherit ITEM;
inherit F_FOOD;
void create()
{
    set_name("���õ���", ({
"xian turou", "turou"}));
    set_weight(300);
    if (clonep())
        set_default_object(__FILE__);
    else {
        set("long", "һ�����õ��⣬�ر��һ�鹻����Գ�3���ˡ�\n");
        set("unit", "��");
        set("value", 5000);
        set("food_remaining", 20);
        set("food_supply", 250);
    }
}
