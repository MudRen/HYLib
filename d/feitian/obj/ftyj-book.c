// ftyj-book.c �ؼ�
// ����(diabio)2001.3.4

#include <ansi.h>
inherit ITEM;
inherit F_UNIQUE;

void create()
{
        set_name(HIY"�����������ؼ��²�" NOR, ({ "mi ji","book", }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
             set("unit", "��");
             set("long",
        "����һ��д�����������飬����һ��������һ�ѷǵ��ǽ�����������վ�š�\n",
         );
         set("value", 0);
         set("material", "silk");
         set("skill", ([
                        "name":       "feitian-yujianliu",
                        "exp_required" : 150000,
                        "jing_cost":  35,
                        "difficulty": 25,
                        "max_skill":  101
                ]) );
        }
//        set("no_drop", "�书�ؼ��ɲ�����㶪����\n");
        set("no_give", "�����������������ˡ�\n");
              set("no_put", "��������ŵ�����ȥ��\n");
}
