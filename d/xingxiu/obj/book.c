
#include <ansi.h>
inherit ITEM;

string book_name();
void create()
{
        set_name("��֪������", ({"noname book"}));
        set_weight(10);
        set_weight(1);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "һ�����ƾɾɵ��飬��֪������ʲô����д�ɵġ�\n");
                set("unit", "��");
                set("material", "paper");
                set("value", 2000);
                set("no_sell", 1);
                set("skill", ([
                         "name":         (: book_name :),// name of the skill
                        //"name":         "xuantian-strike",// name of the skill
                        "jing_cost":    100,            // jing cost every time study this
                        "difficulty":   50,             // the base int to learn this skill
                        "min_skill":    50,            // the maximum level you can learn
                        "max_skill":    200,            // the maximum level you can learn
                ]) );
        }
}

string book_name()
{
        if( random(2) ) return "xuantian-strike";
        return "bingpo-blade";
}

