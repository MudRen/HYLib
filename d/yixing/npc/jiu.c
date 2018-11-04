// Éñ»°ÊÀ½ç¡¤Î÷ÓÎ¼Ç¡¤°æ±¾£´£®£µ£°
/* <SecCrypt CPL V3R05> */
 
                 // wine.c ½­Ã×¾Æ

inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("Ðþ±ù±Ì»ð¾Æ", ({"jiu"}));
        set_weight(100);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "Ðþ±ù±Ì»ð¾Æ¡£\n");
                set("unit", "Íë");
                set("value", 120);
     set("food_remaining",6);
                set("food_supply", 20);
        }

        // because a container can contain different liquid
        // we set it to contain wine at the beginning
        set("liquid", ([
                "type": "alcohol",
                "name": "Ðþ±ù±Ì»ð¾Æ",
                "drunk_apply": 10,
        ]));
}
