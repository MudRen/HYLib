#include <weapon.h>
#include <ansi.h>
inherit SWORD; 
void create()
{
        set_name(HIW"���Ǻ�˪��"NOR, ({ "ice sword"}) );
        set_weight(50);
        if( clonep() )
                set_default_object(__FILE__);
        else 
        {
                set("unit", "��");
                set("long", "һ�Ѿ�Ө��͸�ı�����ͨ���ף����������������Ƴɡ�\n");
                set("material", "ice");
        set("wield_msg", "����һ����һ��$n��Ȼ����$N���У����¶�ʱ������ߡ���\n");
        set("unwield_msg", "$N��һ�$n�Ѳ��ڱ���\n");
        
        }
        ::init_sword(880);
       
        //call_out("check_status",1);
}    
void init(){
        add_action("do_wield", "get");
        add_action("do_wield", "wield");
        add_action("do_wield", "give");
}  
int check_status()
{
        object me;
        
        me=environment();
    if(objectp(me) && living(me)&&(me->query("force_factor")>=80)&&(me->query("neili")>=100)) {
        me->add("neili",-25);
        call_out("check_status",10+random(20));
                return 1;
        }
        call_out("dissolve",1);
        return 1;
} 
mixed hit_ob(object me,object victim)
{       string msg; 
    if(!random(5)&&(!victim->query_temp("is_unconcious")))
        {
                msg=HIW"$n��Ȼ����ȫ����׹����ߣ���һ�������ܶ��ˣ���\n"NOR;
                victim->set_temp("disable_inputs",1);
                victim->set("disable_type",HIW "<������>"NOR);
                victim->set_temp("is_unconcious",1);
                call_out("remove_frozen",10,victim);
                return msg;
        }
        return 0;
} 
int dissolve()
{
        object holder,room;
        
        if(!objectp(holder=environment())) {
                destruct(this_object());
        }
        
        if(userp(holder))
                room=environment(holder);
        else room=holder;
        message("vision",this_object()->query("name")+"�����Ļ�����һ̲��ˮ��\n",room);
        destruct(this_object());
        return 1;
}
        
void remove_frozen(object me)
{
    me->delete("disable_type");
    me->delete_temp("disable_inputs");
    me->delete_temp("is_unconcious");
    if(!me->is_ghost())
        message_vision(HIR "\n\n$N����һ��ŭ��˫��һ�񣬽��������۵ı�����÷��飡��\n\n"NOR, me);
} 
int do_wield(string arg) {
        call_out("check_status", 2);
        return 0;
}   
