#include <ansi.h>
inherit ITEM; 
void create()
{
        set_name(HIW"����"NOR, ({ "secret order" }) );
        set_weight(1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("material", "paper");
        set("long", "һ����Ѻ�������õ������δ��֪����ӡ��\n");
        }
    setup();
} 
void init()
{
        add_action("do_show", "show");
        add_action("do_look","look");
}
void del_show_order(object ob)
{
        ob->delete_temp("show_order");
        destruct(this_object());
        return;
} 
int do_look (string arg)
{
        if (arg=="secret order")
        if (this_object()->query("sealed")!=1){
                tell_object(this_player(),"һ����Ѻ�������õ������δ��֪����ӡ��\n");
                return 1; 
        } else {
                tell_object(this_player(),"һ����Ѻ�������õ�����������һ��֪����ӡ��\n");
                return 1;
                }
        return 0;
}        
int do_show(string arg)
{
   object obj; 
        if (environment(this_object())!=this_player() || !arg)
                return 0;
        if (!objectp(obj=present(arg,environment(this_player()))))
                return notify_fail("��Ҫ�������ø�˭����\n");
        if (!living(obj))
                return notify_fail("��....����Ȱ�" + obj->query("name") +"Ū����˵��\n");
        
        message_vision("$N��"+this_object()->query("name")+"��ʾ��$n����\n",this_player(),obj); 
        if (obj->query("prison_guard")){
                        if (this_object()->query("sealed")==1){
                        if (this_player()->query("combat_exp")<1500000) {
                                message_vision("$N�û��ɵ��۹⿴�˿�$n˵����ƾ���������ӣ�Ҳ��Ѻ�ⷸ�ˣ�\n",obj,this_player());
                                return notify_fail("�������������������㡣\n");
                        }
                        message_vision("$N����ϸϸ���˿������ɫ���ص������˾������档\n",obj);
                        message_vision("$N�������ϵĴ�ͭ��������ʾ��������ˣ��������ߡ�\n",obj);
                        environment(obj)->do_open();
                        if (obj->query("prison_guard")==1)
                                this_player()->set_temp("show_order",1);
                        else{
                                this_object()->move(obj);
                                call_out("del_show_order",300 , this_player());
                        }
                }
                else{
                        message_vision("$N��ϸһ������ɫ��������Ȼ��ͼ�ɻ���أ����˰����д��˽�������\n",obj);
                        obj->do_alert(this_player());
                }
        }
        else{
                if (!userp(obj)){
                        if (obj->query("vendetta_mark")=="authority"){
                                message_vision("$N����$nһ�ۣ�˵�������ǹٸ�֮���Ӻδ�������\n",obj,this_player());
                        }
                        else{
                                message_vision("$N�����"+this_object()->query("name")+"ûʲô��Ȥ��\n",obj);
                        }
                }
        } 
   return 1;
}  
