
 
inherit ITEM;
inherit F_FOOD;

int do_eat(string arg);

void create()
{
   set_name("�����Ｙ", ({"liji"}));
        set_weight(100);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "���ǾŽ�����¥�����˻����Ｙ��\n");
                set("unit", "��");
                set("value",400);
                //set("no_decay",1);
                set("food_remaining",100);
                set("food_supply",100);
        }
}

