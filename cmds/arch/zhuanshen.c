#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string str)
{
    int i,temp;
    object obj;
mapping hp_status, skill_status, map_status, prepare_status;
mapping my;
string *sname, *mname, *pname;

    if( !str || str == "")
        return notify_fail("��Ҫ��˭ת��?\n");

    if ( !obj = present(str,environment(me)))
        return notify_fail("����û��"+str+"\n");
    
    if ( !userp(obj))
        return notify_fail("�ⲻ����Ұ�?\n");

    if ( obj->query("zhuanshen"))
        return notify_fail("�����Ѿ�ת������!\n");

    if ( (int)obj->query("combat_exp") < 5000000)
        return notify_fail("����û���ʸ�ת��!\n");


    obj->set("eff_qi",obj->query("max_qi"));
    obj->set("qi",obj->query("max_qi"));
    obj->set("eff_jing",obj->query("max_jing"));
    obj->set("jing",obj->query("max_jing"));
    obj->set("jingli",obj->query("max_jingli"));
    obj->set("neili",obj->query("max_neili"));
    obj->set("food",obj->max_food_capacity());
    obj->set("water",obj->max_water_capacity());
    obj->clear_condition();
if (mapp(skill_status = obj->query_skills()))//�ж��Լ��Ƿ��й������н����������ȫ��ɾ��
{
skill_status = obj->query_skills();
sname = keys(skill_status);//���������Լ��Ĺ�������

temp = sizeof(skill_status);
for (i = 0; i < temp; i++)
obj->delete_skill(sname[i]);//ɾ���Լ����й���
}
		obj->map_skill("unarmed");
		obj->map_skill("hammer");
		obj->map_skill("blade");
		obj->map_skill("stick");
		obj->map_skill("staff");
		obj->map_skill("club");
		obj->map_skill("throwing");
		obj->map_skill("parry");
		obj->map_skill("dodge");
		obj->map_skill("magic");
		obj->map_skill("spells");
		obj->map_skill("leg");
		obj->map_skill("axe");
		obj->map_skill("array");
		obj->map_skill("whip");	
		obj->map_skill("finger");
		obj->map_skill("hand");	
		obj->map_skill("cuff");	
		obj->map_skill("claw");	
		obj->map_skill("strike");	

		obj->prepare_skill("unarmed");
		obj->prepare_skill("hammer");
		obj->prepare_skill("blade");
		obj->prepare_skill("stick");
		obj->prepare_skill("staff");
		obj->prepare_skill("club");
		obj->prepare_skill("throwing");
		obj->prepare_skill("parry");
		obj->prepare_skill("dodge");
		obj->prepare_skill("magic");
		obj->prepare_skill("spells");
		obj->prepare_skill("leg");
		obj->prepare_skill("axe");
		obj->prepare_skill("array");
		obj->prepare_skill("whip");	
		obj->prepare_skill("finger");
		obj->prepare_skill("hand");	
		obj->prepare_skill("cuff");	
		obj->prepare_skill("claw");	
		obj->prepare_skill("strike");	
                obj->reset_action();
                obj->set("combat_exp",300000);
            obj->set("potential",obj->query("learned_points")+100000);
// 1
        if ( obj->query("per")*2 > 50)
        {
	obj->set("per",50);
        }
        else obj->set("per",obj->query("per")*2);

//2
        if ( obj->query("str")*2 > 50)
        {
	obj->set("str",50);
        }
        else obj->set("str",obj->query("str")*2);

//3
        if ( obj->query("dex")*2 > 50)
        {
	obj->set("dex",50);
        }
        else obj->set("dex",obj->query("dex")*2);

//4
        if ( obj->query("int")*2 > 50)
        {
	obj->set("int",50);
        }
        else obj->set("int",obj->query("int")*2);

//5
        if ( obj->query("con")*2 > 50)
        {
	obj->set("con",50);
        }
        else obj->set("con",obj->query("con")*2);


//6
        if ( obj->query("kar")*2 > 50)
        {
	obj->set("kar",50);
        }
        else obj->set("kar",obj->query("kar")*2);

        obj->set("betrayer",0);
        obj->set("title","��ͨ����");
        obj->set("class","0");
        obj->set("score",0);
        obj->set("shen",0);
        obj->set("max_neili",0);
        obj->set("max_qi",100);
        obj->set("max_jing",100);
        obj->delete("family");
        obj->delete("party");
obj->delete("work/wakuang");
obj->delete("work/wunon");
obj->delete("work/penlen");
obj->delete("work/zhujian");
obj->delete("work/zhudao");
obj->delete("work/zhubanzi");
obj->delete("work/buyu");
obj->delete("work/dalie");
obj->delete("work/zhaojiu");
obj->delete("work/zhujia");
obj->delete("work");
obj->delete("breakup");
obj->delete("last_getzhen");
obj->set("tforceok",2);
        obj->set("killbyname",0);
        obj->set("MKS",0);
        obj->set("PKS",0);
        obj->set("zhuanshen",1);
        obj->set("meili",0);
        obj->set("dietimes",0);
        obj->set("normal_die",0);
        obj->set("weiwang",0);
        obj->set("mud_age",400000);
        obj->save();
    write(HIR"ת���ɹ�,�����µ�½!\n"NOR);
tell_object(obj,HIR"ת���ɹ�,�����µ�½!\n"NOR);
    "/cmds/usr/quit"->main(obj);

    return 1;
}

int help(object obj)
{
  write(@HELP
ָ���ʽ : zhuanshen <����>

���ô�ָ���Ϊ��ҽ���ת�������ת����
����Ϊ300K,Ǳ��Ϊ100K,�������Գ�����
(����50).18�꿪ʼ��ԭ���书ȫ����ʧ��
��ԭ�е��̵��ߣ��������������ȫ�����档
HELP
    );
    return 1;
}

