
 
inherit ITEM;

void create()
{
   set_name("���", ({"qing jian","jian"}));
        set_weight(100);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "����һ�������\n");
                set("unit", "��");
				set("li_songxin_job",1);
                
        }
}

