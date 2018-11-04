//Cracked by Roath
// tongbo.c
// updated by wsky

#include <ansi.h>

//inherit F_CLEAN_UP;
inherit ITEM;

void create()
{
        set_name("ͭ��", ({ "tongbo" }) );
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ�Խ��������ͭ�ࡣ���ƺ�������������ƨ(paima)\n");
                set("value", 0);
                set("material", "iron");
        }
        setup();
}


void init()
{
        add_action("do_flatter","paima");
}

int do_flatter(string arg)
{

        string* flatter = ({
                "$N����ͭ�࣬����ߺ���ţ���$n���ɣ�������أ��������Ž��ޱȣ���",
                "$N���µ�����$n���ɽ���������ԭ�������������ɵ���������",
                "$N������ɫ�Ŀ���$n������˵������������Щ��ԭ��򣬻�����$n���ɵ�һ��Сָ����",
                "$N����ĺ�������$n������һ��ɽ�����ѣ���һң�����޹⡣��",
                "$N�����Աߵ��ˣ�����˵������˭�ҵ���$n���ɣ��ҵ�һ������ƴ������˵�꿴�˿���·��",
                "$N˵������˭��$n���ɱ��䣬��ֱ���۵������Բ������𡣡�",
                "$N˵������$n�������˰���$n���������̡���",
                "$N�е�: ��$n�����ɸ�,��������!��\n",
                "$N�е�: ��$n��Ŀ��磬�����ķ�����\n",
                "$N�е�: ���˷����˳�Ӣ��,$n��ͬ���¹⡣��\n",
        });

        int skill,int1,int2,b1,b2;
        object me,obj;
        string msg;
        mapping myfam, vtfam;
        
        me=this_player();


        skill = me->query("flattering");

        if (!skill) skill=10;
        if(skill<300) skill=30;
                else if(skill>300 && skill < 600) skill=60;
                else if(skill>600) skill=100;

        if( !arg ) return notify_fail("������˭����ƨ��\n");

        if(arg==me->query("id")) return notify_fail("���Լ���ƨ����\n");
if (environment(me)->query("sleep_room"))
                return notify_fail("��������ƨ����Ӱ�������Ϣ��\n");

if( environment(me)->query("no_beg") &&
      environment(me)->query("no_fight") &&
       environment(me)->query("no_steal")) 
          return notify_fail(HIY"\n��ҪӰ����ˣ�������һ����ĵط��ɡ�\n"NOR);

        if( !objectp(obj = present(arg, environment(me)) ))
                return notify_fail("�����Ѿ��뿪����ط��ˡ�\n");

if( !obj->is_character()
|| !living(obj))
return notify_fail("ֻ�ܶ�����������ƨ��\n");
        if (me->is_fighting()) return notify_fail("����л�������ƨ�������ǲ�Ҫ�������ˡ�\n");

	if( me->is_busy() ) return notify_fail("( ����һ��������û����ɣ�����ʩ���⹦��)\n");

	if( environment(me)->query("no_fight") ) return notify_fail("�����ﻹ������ƨ��\n");

        if ( (!( myfam= me->query("family")) || myfam["family_name"] != "������"))
          return notify_fail("ֻ�����޵��Ӳ������������Ƥ��\n");

        if( me->query_temp("flattering") )
                return notify_fail("���Ѿ��ڹ��ž�������ƨ�ˡ�\n");
    
//        if ( (vtfam = obj->query("family")) && vtfam["family_name"] != "������")
//                return notify_fail("��ֻ�������޵�����ƨ��\n");
        
//        if (userp(obj)) return notify_fail("���������ƨ��tell��!\n");
        
        if (obj->query("combat_exp")<(me->query("combat_exp"))/3*2) return notify_fail("���˹���̫�ֵ������\n");
	
        if (obj->query_temp("flattered")) return notify_fail("��"+RANK_D->query_rude(obj)+"����������ѬѬȻ���ء�\n");

        if (obj->query_temp("angry")) {
                message_vision(HIR"$n����ŭ�����֣�ȫ����$N������$N����һ���������ƨ�ĵ�������ˡ�\n"NOR,me,obj);
                me->start_busy(random(2)+1);
		obj->set_temp("yield",0);
if (!userp(obj) && random(12)==0)
{
		if( !me->is_killing(obj) ) me->fight_ob(obj);
}else 
{
		me->start_busy(12);
}
                return 1;
        }

        msg=flatter[random(sizeof(flatter))];
        message_vision(HIM+msg+"\n"+NOR,me, obj);
        int1=me->query("int");int2=obj->query("int");
        if(random(int1*100)>random(int2*100)){
                message_vision(HIG"$n�����Ժ�������ЩƮƮȻ�ģ��ƺ��Թ�����Щ�Ʋ�������ЧӦ��\n"NOR,me,obj);

                me->set_temp("flattering",1);

//                obj->add_temp("apply/damage", skill/3);
//                obj->add_temp("apply/parry", skill/3);
//                obj->add_temp("apply/dodge", skill/3);

                me->add("jing",-me->query("max_jing")/12);
                me->add("qi",-me->query("max_qi")/12);
                me->add("flattering",1);

                me->start_busy(4);
b1=18+random(38);
b2=12+random(22);
me->add("combat_exp", 16+b1);
me->add("potential", 10+b2);
message_vision("$N�ľ������"+chinese_number(16+b1)+"�㡣\n", me);
message_vision("$N��Ǳ�ܼ���"+chinese_number(10+b2)+"�㡣\n", me);
                obj->set_temp("flattered",1);
if (me->query("combat_exp") >1000000)
                call_out("remove_effect", 25, me, obj); 
else            call_out("remove_effect", 12, me, obj); 
        } else {
                message_vision(HIB"$n����$Nһ�ۣ�һ����ߡ�\n"NOR,me,obj);                      
                obj->set_temp("angry",1);
if (me->query("combat_exp") >1000000)
{
                call_out("remove_effect", 25, me, obj); 
                call_out("remove_effect2", 12, me, obj); 
}
else
{
call_out("remove_effect", 18, me, obj); 
           call_out("remove_effect2", 18, me, obj); 
}
        }
        return 1;
}


int remove_effect(object me, object obj, int skill){            
if (!me) return 1;
if (!obj) return 1;
        me->delete_temp("flattering");
        obj->delete_temp("flattered",1);
        message_vision(HIY"$N��������˿�����������ɤ�ӡ�\n"NOR,me,obj);
}

int remove_effect2(object me, object obj){
if (!me) return 1;
if (!obj) return 1;
        obj->delete_temp("angry");
        message_vision(HIY"$n��ɫ�Լ����͡�\n"NOR,me,obj);
}
