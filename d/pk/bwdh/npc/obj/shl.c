// shenghuo-ling.c

#include <weapon.h>
inherit BLADE;
inherit F_UNIQUE;

void create()
{
        set_name("ʥ����", ({ "shenghuo ling","shenghuo","ling" }));
        set_weight(9000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ���������������ƣ��ʵع��죬���Ǽ�Ӳ�������̵�ʥ�\n"
                        "���������л��ݷ��ڣ���͸������͸����������в��ٵĲ�˹���֡�\n");
                set("value", 10);
                set("material", "steel");
                set("rigidity", 9);
                set("weapon_prop/parry", 1);
                set("weapon_prop/dodge", 1);
                set("wield_msg", "$N��ৡ���һ�����һ��$n�������С�\n");
                set("unwield_msg", "$N�����е�$n������䡣\n");                
                set("treasure",1);
        }               
         init_blade(100);
        setup();
}

void init()
{
        add_action("do_du", "du");
        add_action("do_du", "study");
}
int do_du(string arg)
{
        object me = this_player();
        object where = environment(me);
        object ob;
        mapping skill;
        int qklevel; 
        int neili_lost;
        if (!(arg=="shenghuo ling" ||arg=="ling"))
                return 0;
        if (where->query("pigging")){
                write("�㻹��ר�Ĺ���ɣ�\n");
                return 1;
        }
        if (me->is_busy()) {
                write("��������æ���ء�\n");
                return 1;
        }

        if( me->is_fighting() ) {
                write("���޷���ս����ר�������ж���֪��\n");
                return 1;
        }

        if (!id(arg)) { 
                write("��Ҫ��ʲô��\n");
                return 1;
        }
       
        if( !me->query_skill("literate", 1) ){
                write("���Ǹ���ä����ѧ���Ļ�(literate)�ɡ�\n");
                return 1;
        }
        if (me->query_int()<33){
                write("�����ʥ�����ϵĲ�˹����������о��������ǲ����������⡣\n");
                return 1;
        }
        if (!me->query_skill("shenghuo-shengong",1)){
                write("���ʥ���񹦻��̫ǳ������������ϵĸ����书���\n");
                return 1;
        }
       if (me->query_skill("shenghuo-lingfa",1)<101){
                write("���ʥ�����̫�ͣ����ܴ���ѧ��ʲô��\n");
                return 1;
        }
        message("vision", me->name() + "�����ж�ʥ���\n", environment(me), me);
         
        if( (int)me->query("jing") < 15 ) {
                write("�����ڹ���ƣ�룬�޷�ר�������ж���֪��\n");
                return 1;
        }
        
        if( (int)me->query("neili") < neili_lost) {
                write("�������������޷�������ô������书��\n");
                return 1;
        }

        qklevel = me->query_skill("shenghuo-lingfa", 1);
        if( (int)me->query("combat_exp") < (int)qklevel*qklevel*qklevel/10 ) {
                write("���ʵս���鲻�㣬����ô��Ҳû�á�\n");
                return 1;
        }
        if (me->query_skill("shenghuo-lingfa",1)>120){
                write("���Ѳ��ܴ�������ѧ���κζ����ˡ�\n");
                return 1;
        }
         neili_lost=(int)(me->query_skill("shenghuo-shengong",1)/10);
        me->receive_damage("jing", 15);
        me->set("neili",(int)me->query("neili")-neili_lost);
        me->improve_skill("shenghuo-lingfa", (int)me->query_skill("literate", 1)/3+1);
        if (me->query_skill("blade",1)<30){
                me->improve_skill("blade", (int)me->query_skill("literate", 1)/3+1);
                return 1;
        }
        write("��������ϰʥ�����ϵ��书���ƺ��е��ĵá�\n");
        return 1;
}
