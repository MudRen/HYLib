
 
inherit ITEM;
inherit F_FOOD;

int do_eat(string arg);

void create()
{
   set_name("���㻨��", ({"huasheng"}));
        set_weight(20);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "����һС������������㻨����\n");
                set("unit", "��");
                set("value",30);
                //set("no_decay",1);
                set("food_remaining",20);
                set("food_supply",30);
        }
}

