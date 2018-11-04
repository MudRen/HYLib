#include <ansi.h>
inherit NPC;
int ask_force2();
int ask_force(string arg);
int ask_me();
int ask_nk();
int ask_zs1();
int ask_zs2();
int ask_zs3();
int ask_zs4();
string ask_clear();
string ask_buchang();
string ask_panshi();
string ask_job();
#include "/clone/guard/party.h"
//int ask_gift();
int ask_bing();
int ask_yahuan();
int ask_yahuan2();
void create()
{
       set_name("������ʿ", ({ "noname", "man" }));
        set("title",HIW"һ����ʦ"NOR);
	set("long", 
              "������������ʿ��û����֪������������\n"
              "��������ռ����飬�����������(book)��(shi).\n"
              );
        set("age", 57);
        set("class", "beggar");
	set("attitude", "friendly");
	set("shen_type", 1);
	set("str", 700);
	set("int", 40);
	set("con", 40);
	set("dex", 700);
	set("no_kill",1);
	set("qi",   99999999);
	set("jing", 99999999);
	set("eff_qi",   99999999);
	set("eff_jing", 99999999);
	set("max_qi",   99999999);
	set("max_jing", 99999999);
	set("neili", 4500);
	set("max_neili", 4500);
	set("jiali", 0);
	set("combat_exp", 25000000);
	set("score", 50000);                
        set_skill("strike",200);
        set_skill("unarmed",200);
        set_skill("dodge",200);
        set_skill("force", 200);
	set_skill("parry", 210);
	set_skill("literate", 200);
	set_skill("canzhi-duanhun",300);
        map_skill("unarmed", "canzhi-duanhun");
        map_skill("parry", "canzhi-duanhun");


set("inquiry", ([
            "book": "���鹲����ʮ�������������help tasks����йط���֪ʶ��",
            "shi": "ֻ�п�"HIR"��"+HIC+"��"+HIY+"��"+HIM+"��"+HIG+"ʯ"NOR+CYN"�����ҵ����飬��ʯ��ʮ��һ�飡",
	     "mengzhu": (: ask_me :),
	     "��ս": (: ask_nk :),
	     "nokill": (: ask_nk :),
	     "һת": (: ask_zs1 :),
	     "��ת": (: ask_zs2 :),
	     "��ת": (: ask_zs2 :),
	     "ת����": (: ask_zs3 :),
	     "finalskill": (: ask_zs3 :),
	     "maxexp": (: ask_zs4 :),
	     "�ɳ�": (: ask_zs4 :), 
	     "zhuanshen": (: ask_zs1 :),
	     "zhuanshenup": (: ask_zs2 :),
	     "˫�ڹ�": (: ask_force2 :),
	     "force": (: ask_force2 :),
	     "����":(: ask_job :),
	     "job":(: ask_job :),
		"���": (: ask_yahuan :),
		"��������": (: ask_yahuan2 :),
		"newguard": (: ask_yahuan2 :),
		"guard": (: ask_yahuan :),
//��Ҫ������ͷ����ֻ�ܿ���һ����������ʱ������!!�����ǹط�����!!
	     "��������":(: ask_clear :),
	     "yaogift":(: ask_clear :),
//       "gift":(: ask_buchang :),
//	     "��������":(: ask_buchang :),
//	     "����":(: ask_buchang :),
//��Ҫ������ͷ����ֻ�ܿ���һ����������ʱ������!!�����ǹط�����!!
            ]) );
       	setup();
}
void init()
{
	add_action("do_answer", "answer");
	add_action("ask_force", "yaoforce");
}
int accept_object(object me, object ob)
{
object shi; 
if( ob->query("money_id") && ob->value() >= 2000)
{	
	 if (!present("xdshi", me))
	{
	shi = new("/clone/misc/findbook");
	command("say �ð�,"+me->query("name")+"��Ȼ����Ǯ���Ҿ͸���һ�飡\n");
	shi->move(me);
	message_vision("$N��һ��"HIR"��"+HIC+"��"+HIY+"��"+HIM+"��"+HIG+"ʯ"NOR"������$n��\n" , this_object(), me );
	} else 
	command("say �㲻������һ�������Ҫ��Ǯ��û�գ�\n");
return 1;
}

command("say лл�����Ҳ�Ҫ�ⶫ����");
return 0;
}
int ask_me()
{
if(this_player()->query("combat_exp")<1500000)  tell_object(this_player(),"������ʿ˵�����㾭��̫�ͣ���Ҫ���������������ɣ�\n");
else {
tell_object(this_player(),"������ʿ˵���� �ðɣ�����Σ�����أ�ǧ�������������������Σ�ա��Լ�С�İɣ�\n");
this_player()->move("/d/biwu/hole");
}
return 1;
}

int ask_nk()
{
if(this_player()->query("PKS",1)> 10 
||this_player()->query_condition("killer")
//||this_player()->query("guard/flag")
||this_player()->query("age") < 18
 )
{
tell_object(this_player(),"������ʿ˵������û���ʸ񣬲���������սϵͳ��\n");
}
else {
tell_object(this_player(),"������ʿ˵���� �ðɣ�����������սϵͳ��\n");
this_player()->set_temp("nokill",1);
}
return 1;
}



string ask_job()
{

        mapping quest,item,npc;
        object me;
        int j, combatexp, timep,factor,num;
        string room;
        string tag = "2000000";
        string *levels = ({
                        "10000",
                        "15000",
                        "20000",
                        "30000",
                        "50000",
                        "80000",
                        "100000",
                        "130000",
                        "170000",
                        "220000",
                        "300000",
                        "450000",
                        "600000",
                        "800000",
                        "1000000",
                        "2000000"
        });

        me = this_player();
        combatexp = (int) (me->query("combat_exp"));
     if ((int)me->query_condition("guojob2_busy"))
if ((int)me->query_condition("nonamejob"))
{
return HIR"����λ"+RANK_D->query_respect(me)+"�Ȼ������ɡ�"NOR;
}

if ((int)me->query_condition("nonamejob"))
{
message_vision(HIY"$N����$nҡ��ҡͷ˵����սӹ�����!�Ȼ�����!\n"NOR, this_object(), me);
return HIR"����λ"+RANK_D->query_respect(me)+"�Ȼ������ɡ�"NOR;
}
        for(j= sizeof(levels) - 1 ; j>=0; j--)
        {
             if( atoi(levels[j])  <= combatexp )
             {
                   num=j;
                   factor=10;
                   break;
             }
        }
        if (num>0)
        {
             if (random(50)>45)
             {
                   num=num-1;
             }
        } 
        else
        {
             if ((num<sizeof(levels)-1)&&(random(100)>95))
             {
                   num=num+1;
                   factor=15;
             }
        }
        tag=levels[num];

item  = QUESTW_D(tag)->query_quest();
npc = QUESTS_D(tag)->query_quest();
if (random(2)==1)
npc = QUESTH_D(tag)->query_quest();
me->set_temp("jobitem",item["quest"]);
me->set_temp("jobnpc",npc["quest"]);
me->apply_condition("nonamejob",8);
tell_object(me,HIC"�ѡ�"HIG+item["quest"]+HIC"���ҵ�����������"HIG+npc["quest"]+HIC"����\n" NOR);
return HIW"����λ"+RANK_D->query_respect(me)+"���ȥ���ɡ�"NOR;
}

void unconcious()
{
	reincarnate();
	set("eff_qi", query("max_qi"));
	set("qi", query("max_qi"));
	set("eff_jing", query("max_jing"));
	set("jing", query("max_jing"));
	set("jingli", query("eff_jingli"));
	say( "������ʿЦ��˵���������û���ã�\n");
	command("hehe");
}

void die()
{
	unconcious();
}

int ask_yahuan2()
{
 	object me = this_player();

	if (!me->query("guard/flag"))
		command("say ƾ�����ڵ���������û���ʸ�����Ҫ����أ�");
	if (!me->query("guard/active"))
		command("say �����ڻ�û�����!");
	else {
		command("nod " + me->query("id"));
		command("say ���Ѿ����¿��Ի�һ����Ů�ˣ�");
		command("say ����ȥ�˷�֮һ�ľ���");
	me->delete("guard/active");
  me->add("combat_exp",-(int)me->query("combat_exp")/8);
	}
	return 1;
}


int ask_yahuan()
{
 	object me = this_player();

	if (!me->query("guard/flag"))
		command("say ƾ�����ڵ���������û���ʸ�����Ҫ����أ�");
	else if (me->query("guard/active"))
		command("say �㲻���Ѿ��������ô��");
	else {
		command("nod " + me->query("id"));
		if (me->query("gender") == "����") {
			command("say ������������һЩ��Ů�����Ƕ������ŵ��ӣ���
\t\t�䵱��\t\t(wudang)
\t\t��ɽ��\t\t(huashan)
\t\t���չ�\t\t(lingjiu)
\t\t�һ���\t\t(taohua)
\t\t��ػ�\t\t(tiandihui)
\t\t����\t\t(mingjiao)
\t\t��Ĺ��\t\t(gumu)
\t\tؤ��\t\t(gaibang)
\t\tȫ���\t\t(quanzhen)
\t\t����\t\t(dali)
\t\t���ư�\t\t(tiezhang)
\t\tĽ������\t(murong)
\t\t������\t\t(kunlun)
\t\t������\t\t(lingxiao)
\t\t�嶾��\t\t(wdjiao)
\t\t����ɽ\t\t(baituo)
\t\t������\t\t(emei)
\t\t��ң��\t\t(xiaoyao)
\t\tѩɽ��\t\t(mizong)
\t\t������\t\t(xingxiu)
\t\t������\t\t(feitian)
\t\t������\t\t(shenlong)
\t\t����\t\t(tangmen)
\t\t���½�\t\t(riyue)
\t\t����\t\t(shaolin)
����Ҫ����һ�������Ѿ��������answer�ش��ң�");
		} else {
			command("say ������������һЩ���ӣ����Ƕ������ŵ��ӣ���
\t\t�䵱��\t\t(wudang)
\t\t��ɽ��\t\t(huashan)
\t\t���չ�\t\t(lingjiu)
\t\t�һ���\t\t(taohua)
\t\t��ػ�\t\t(tiandihui)
\t\t����\t\t(mingjiao)
\t\t��Ĺ��\t\t(gumu)
\t\tؤ��\t\t(gaibang)
\t\tȫ���\t\t(quanzhen)
\t\t����\t\t(dali)
\t\t���ư�\t\t(tiezhang)
\t\tĽ������\t(murong)
\t\t������\t\t(kunlun)
\t\t������\t\t(lingxiao)
\t\t�嶾��\t\t(wdjiao)
\t\t����ɽ\t\t(baituo)
\t\t������\t\t(emei)
\t\t��ң��\t\t(xiaoyao)
\t\tѩɽ��\t\t(mizong)
\t\t������\t\t(xingxiu)
\t\t������\t\t(feitian)
\t\t������\t\t(shenlong)
\t\t����\t\t(tangmen)
\t\t���½�\t\t(riyue)
\t\t����\t\t(shaolin)
����Ҫ����һ���������ͯ������answer�ش��ң�");
		}
		me->set_temp("guard/answer", 1);
	}
	return 1;
}
int do_answer(string arg)
{
	object me = this_player(), ob;
	int i, flag = 0;
	
	if (!me->query_temp("guard/answer"))
		return 0;
		
	// Ҫ����������Ҫһ�����������ƣ�
	for (i = 0; i < sizeof(ps); i++)
		if (arg == ps[i]["party"]) {
			flag = 1;
			break;
		}
	if (!flag) {
		command("kick " + me->query("id"));
		command("say ����Ҫ������ҿ�û�У�");
		return 1;
	}
	command("ok");
	me->delete_temp("guard/answer");

	me->delete("guard/status");
	me->delete("guard/skills");
	me->delete("guard/gender");
	me->delete("guard/learned");
	me->delete("guard/skill_map");
	me->delete("guard/skill_prepare");
	me->set("guard/flag", 1);
	me->set("guard/active", 1);
	if (me->query("gender") == "����")
		me->set("guard/gender", "girl");
	else
		me->set("guard/gender", "boy");
	me->set("guard/status", ps[i]["status"]);
	me->set("guard/skills", ps[i]["skills"]);
	me->set("guard/learned", ps[i]["learned"]);
	me->set("guard/skill_map", ps[i]["skill_map"]);
	me->set("guard/skill_prepare", ps[i]["skill_prepare"]);
	me->save();
	
	command("say �ӽ��������͸������ˣ������ʹ��(zhaohuan)�������ٻ�����");
		
	return 1;
}

/*string ask_panshi()
{

        mapping quest,item,npc;
        object me=this_player();
if (me->query("npanshi"))
return HIR"����λ"+RANK_D->query_respect(me)+"���Ѿ�Ϊ�������ʦ��¼�ˡ�"NOR;
command("say ����ϵͳ�������Ͱ���һ�ΰ�");
me->set("betrayer",0);
me->set("npanshi",1);
return HIW"����λ"+RANK_D->query_respect(me)+"�Ժ�Ҫ�ú����ˡ�"NOR;
}
*/

string ask_buchang()
{
        mapping quest,item,npc;
        object ob;
        object me=this_player();
if ((int)me->query("combat_exp") < 5000)
return HIR"����λ"+RANK_D->query_respect(me)+"�����ְɡ�"NOR;
  if(me->query("liwuopen/1")>0)
return HIR"����λ"+RANK_D->query_respect(me)+"�Ѿ����ù��˰ɡ�"NOR;
  if(me->query("liwuopen/2")>0)
return HIR"����λ"+RANK_D->query_respect(me)+"�Ѿ����ù��˰ɡ�"NOR;

 me->set("liwuopen/2",1);
 ob=new("/clone/gift/biggift");
        ob->set_amount(1);
        ob->move(me);
return HIR"����λ"+RANK_D->query_respect(me)+"���տ��֡�ף���彡��!!"NOR;
}
string ask_clear()
{
        mapping quest,item,npc;
        object ob;
        object me=this_player();

 me->delete("liwuopen");

return HIW"����λ"+RANK_D->query_respect(me)+"���Ѿ�������ˡ�"NOR;
}


int ask_zs1()
{
    int i,temp;
    object obj;
mapping hp_status, skill_status, map_status, prepare_status;
mapping my;
string *sname, *mname, *pname;

obj=this_player();

    if (obj->is_fighting()) 
        return notify_fail("���������������!\n");    

     if(obj->is_busy())
        return notify_fail("��������æ��û��ɱ�ˡ�\n");

    if ( !userp(obj))
        return notify_fail("�ⲻ����Ұ�?\n");

    if ( obj->query("zhuanshen"))
{
command("say ���Ѿ�ת������!");
        return notify_fail("�����Ѿ�ת������!\n");
}
    if (!obj->query("migong/lev3")
    ||!obj->query("migong/lev2")
    ||!obj->query("migong/lev1"))
{
command("say ��û���ʸ�ת��!����������Թ����񵽵�3��!");
        return notify_fail("����û���ʸ�ת��\n");
}
    if ( (int)obj->query("combat_exp") < 8000000)
{
command("say ��û���ʸ�ת��!��Ҫ8M���顣");
        return notify_fail("����û���ʸ�ת��!��Ҫ8M���顣\n");
}
    if ( (int)obj->query("max_neili") < 5000)
{
command("say ��û���ʸ�ת��!�����������!!");
        return notify_fail("����û���ʸ�ת��!\n");
}
   if(obj->query_skill("dodge",1)<300 ||
		obj->query_skill("force",1)<300 ||
		obj->query_skill("parry",1)<300 ||
		obj->query_skill("unarmed",1)<300 ||
		obj->query_skill("literate",1)<300)
{
command("say ��û���ʸ�ת��!����书�ȼ�����!!");
        return notify_fail("����û���ʸ�ת��!\n");
}
		
		
		
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
        if ( obj->query("per")+10 > 50)
        {
	obj->set("per",50);
        }
        else obj->set("per",obj->query("per")+10);

//2
        if ( obj->query("str")+10 > 50)
        {
	obj->set("str",50);
        }
        else obj->set("str",obj->query("str")+10);

//3
        if ( obj->query("dex")+10 > 50)
        {
	obj->set("dex",50);
        }
        else obj->set("dex",obj->query("dex")+10);

//4
        if ( obj->query("int")+10 > 50)
         {
	obj->set("int",50);
        }
        else obj->set("int",obj->query("int")+10);

//5
        if ( obj->query("con")+10 > 50)
        {
	obj->set("con",50);
        }
        else obj->set("con",obj->query("con")+10);


//6
        if ( obj->query("kar")+10 > 50)
        {
	obj->set("kar",50);
        }
        else obj->set("kar",obj->query("kar")+10);

        obj->set("betrayer",0);
        obj->set("title","��ͨ����");
        obj->set("class","0");
        obj->set("score",0);
        obj->set("shen",0);
        obj->set("max_neili",0);
        obj->set("max_qi",105);
        obj->set("max_jing",105);
        obj->delete("family");
        obj->delete("party");
obj->delete("blade_get");
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
        obj->set("killbyname",0);
        obj->set("MKS",0);
        obj->set("zhuanshen",1);
        obj->set("meili",0);
        obj->set("dietimes",0);
        obj->set("normal_die",0);
        obj->set("weiwang",0);
        obj->set("mud_age",400000);
        obj->save();
obj->set("tforceok",2);
    write(HIR"ת���ɹ�,�����µ�½!\n"NOR);
tell_object(obj,HIR"ת���ɹ�,�����µ�½!\n"NOR);
	log_file("static/ZS",
		sprintf("%s һת��ʱ��: %s\n", geteuid(obj), ctime(time())) );

        CHANNEL_D->do_channel(this_object(), "rumor", "��˵" + obj->name(1) +
                              "һת�ˡ�");
    "/cmds/usr/quit"->main(obj);

    return 1;
}

int ask_zs2()
{
    int i,temp;
    object obj;
mapping hp_status, skill_status, map_status, prepare_status;
mapping my;
string *sname, *mname, *pname;

obj=this_player();

    if (obj->is_fighting()) 
        return notify_fail("���������������!\n");    

     if(obj->is_busy())
        return notify_fail("��������æ��û��ɱ�ˡ�\n");

    if ( !userp(obj))
        return notify_fail("�ⲻ����Ұ�?\n");

    if ( !obj->query("zhuanshen"))
{
command("say ��û����һת!");
        return notify_fail("����û����һת!\n");
}
    if (!obj->query("migong/lev8")
    ||!obj->query("migong/lev4")
    ||!obj->query("migong/lev5")
    ||!obj->query("migong/lev6")
    ||!obj->query("migong/lev7"))
{
command("say ��û���ʸ�ת��!����������Թ����񵽵�8��!");
        return notify_fail("����û���ʸ�ת��\n");
}
    if ( (int)obj->query("combat_exp") < 18000000)
{
command("say ��û���ʸ�ת��!��Ҫ18M���顣");
        return notify_fail("����û���ʸ�ת��,��Ҫ18M����!\n");
}
    if ( (int)obj->query("max_neili") < 6000)
{                   
command("say ��û���ʸ�ת��!�����������!!");
        return notify_fail("����û���ʸ�ת��!\n");
}

   if(obj->query_skill("dodge",1)<400 ||
		obj->query_skill("force",1)<400 ||
		obj->query_skill("parry",1)<400 ||
		obj->query_skill("unarmed",1)<400 ||
		obj->query_skill("literate",1)<300)
{
command("say ��û���ʸ�ת��!����书�ȼ�����!!");
        return notify_fail("����û���ʸ�ת��!\n");
}

if (obj->query("guard/flag"))
{
    if (obj->query("guard/flag") && !obj->query("migong/lev12")
    ||!obj->query("migong/lev9")
    ||!obj->query("migong/lev10")
    ||!obj->query("migong/lev11"))
{
command("say ��û���ʸ�3ת!����������Թ����񵽵�12��!");
        return notify_fail("����û���ʸ�3ת!\n");
}
}
    if (obj->query("guard/flag") && (int)obj->query("combat_exp") < 38000000 )
{
command("say ��û���ʸ�3ת!3ת��Ҫ38M���� ");
        return notify_fail("����û���ʸ�3ת!3ת��Ҫ38M����\n");
}


if (obj->query("guard/flag")
&& (int)obj->query("combat_exp") > 38000000 )
{
obj->delete("last_alert");
    write(HIR"3ת�ɹ�!\n"NOR);
obj->set("jiuyin/full",1);
    write(HIR"���Ӿ���!\n"NOR);
obj->set("szj/passed",1);
    write(HIR"��������!\n"NOR);
    obj->set("zhuanbest",1);
obj->delete("last_alert");
}
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
        if ( obj->query("per") < 60)
        {
	obj->set("per",obj->query("per")+10);
        }
        if ( obj->query("str") < 60)
        {
	obj->set("str",obj->query("str")+10);
        }
        if ( obj->query("dex")< 60)
        {
	obj->set("dex",obj->query("dex")+10);
        }
        if ( obj->query("int")< 60)
        {
	obj->set("int",obj->query("int")+10);
        }
        if ( obj->query("con")< 60)
        {
	obj->set("con",obj->query("con")+10);
        }
        if ( obj->query("kar")< 60)
        {
	obj->set("kar",obj->query("kar")+10);
        }

        obj->set("betrayer",0);
        obj->set("title","��ͨ����");
        obj->set("class","0");
        obj->set("score",0);
        obj->set("shen",0);
        obj->set("max_neili",0);
        obj->set("max_qi",105);
        obj->set("max_jing",105);
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
        obj->set("killbyname",0);
        obj->set("MKS",0);
        obj->set("zhuanshen",1);
        obj->set("meili",0);
        obj->set("dietimes",0);
        obj->set("normal_die",0);
        obj->set("weiwang",0);
        obj->set("mud_age",400000);
                obj->set("combat_exp",0);
obj->set("learned_points",0);
obj->set("potential",obj->query("learned_points"));

obj->delete("blade_get");
obj->delete("szj/failed");
obj->delete("jiuyin/shang-failed");
obj->delete("jiuyin/xia-failed");
obj->delete("zhou/fail");
obj->delete("zhou/jieyi");
obj->delete("jiuyin/gumu-failed");
obj->delete("zhou/failed");
//obj->delete("jiuyin");
//obj->delete("szj");
//obj->delete("zhou");
obj->set("guard/flag",1);
obj->set("tforceok",2);
        obj->save();
    write(HIR"ת���ɹ�,�����µ�½!\n"NOR);
tell_object(obj,HIR"ת���ɹ�,�����µ�½!\n"NOR);
if (obj->query("zhuanbest"))
{
	log_file("static/ZS",
		sprintf("%s ��ת��ʱ��: %s\n", geteuid(obj), ctime(time())) );
CHANNEL_D->do_channel(this_object(), "rumor", "��˵" + obj->name(1) +"��ת�ˡ�");
}
else
{
	log_file("static/ZS",
		sprintf("%s ��ת��ʱ��: %s\n", geteuid(obj), ctime(time())) );
CHANNEL_D->do_channel(this_object(), "rumor", "��˵" + obj->name(1) +"��ת�ˡ�");
}
    "/cmds/usr/quit"->main(obj);

    return 1;
}

int ask_force(string arg)
{
    int i,temp,j;
    object obj;
mapping hp_status, skill_status, map_status, prepare_status;
mapping my;
string *sname, *mname, *pname;

obj=this_player();
if (!arg)
return notify_fail("��ҪҪ��ʲô�أ�\n");
if (obj->is_busy())
{
command("say ����æ����!");
        return notify_fail("����æ����!\n");
}
    if (obj->is_fighting()) 
        return notify_fail("���������������!\n");    

    if ( !userp(obj))
        return notify_fail("�ⲻ����Ұ�?\n");

    if ( !obj->query("zhuanshen")
    &&!obj->query("guard/flag")
    &&!obj->query("zhuanbest")
    )
{
command("say ��û������ʹ�������ڹ�!");
        return notify_fail("��û���ʸ�ʹ�������ڹ�!\n");
}
    if ( !obj->query("tforceok"))
{
command("say ���Ѿ���������������!");
        return notify_fail("��û���ʸ�ʹ�������ڹ�!\n");
}

    if ( (int)obj->query("tforceok")==1)
{
command("say �Ҳ����Ѿ�������������������!");
        return notify_fail("��û���ʸ�ʹ�������ڹ�!\n");
}

    if ( (int)obj->query("combat_exp") < 800000)
{
command("say ������һ���书����!ֻ��һ�λ���!!");
        return notify_fail("������һ���书����!\n");
}
    if ( (int)obj->query("combat_exp") < 1000000)
{
command("say ��������һ���ڹ�������!ֻ��һ�λ���!!");
        return notify_fail("������һ���书����!\n");
}
if (mapp(skill_status = obj->query_skills()))//�ж��Լ��Ƿ��й������н����������ȫ��ɾ��
{
j =0;
skill_status = obj->query_skills();
sname = keys(skill_status);//���������Լ��Ĺ�������
temp = sizeof(skill_status);
for (i = 0; i < temp; i++)
if (SKILL_D(sname[i])->exert_function_file() 
&& sname[i]!="force"
&& sname[i]!="taixuan-gong"
&& sname[i]!="jiuyin-zhengong")
{
j=j+1;
}
CHANNEL_D->do_channel(this_object(), "rumor", "��˵" + obj->query("name") +"����" + j +"���ڹ���");
}
if (j < 1) 
{
command("say ����ѧһ���ڹ�����!����ֻ��һ��!!");
        return notify_fail("������һ���书����!\n");
}

if (j > 5) 
{
command("say ���Ѿ��������ڹ���!!����ֻ��һ��!!");
        return notify_fail("������һ���书����!\n");
}

if (arg=="wudang")
{
obj->set_skill("taiji-shengong",105);
obj->set("tforceok",1);
	log_file("static/ZS",
		sprintf("%s Ҫ�ڹ�������: %s\n", geteuid(obj), arg) );
}
else if (arg=="huashan")
{
obj->set_skill("zixia-shengong",105);
obj->set_skill("huashan-neigong",105);
obj->set("tforceok",1);
	log_file("static/ZS",
		sprintf("%s Ҫ�ڹ�������: %s\n", geteuid(obj), arg) );
}
else if (arg=="lingjiu")
{
obj->set_skill("beiming-shengong",105);
obj->set_skill("bahuang-gong",105);
obj->set("tforceok",1);
	log_file("static/ZS",
		sprintf("%s Ҫ�ڹ�������: %s\n", geteuid(obj), arg) );

}
else if (arg=="mingjiao")
{
obj->set_skill("jiuyang-shengong",105);
obj->set_skill("shenghuo-shengong",105);
obj->set("tforceok",1);
	log_file("static/ZS",
		sprintf("%s Ҫ�ڹ�������: %s\n", geteuid(obj), arg) );

}
else if (arg=="shaolin")
{
obj->set_skill("yijinjing",105);
obj->set_skill("hunyuan-yiqi",105);
obj->set("tforceok",1);
	log_file("static/ZS",
		sprintf("%s Ҫ�ڹ�������: %s\n", geteuid(obj), arg) );

}
else if (arg=="xueshan")
{
obj->set_skill("longxiang",105);
obj->set_skill("xiaowuxiang",105);
obj->set("tforceok",1);
	log_file("static/ZS",
		sprintf("%s Ҫ�ڹ�������: %s\n", geteuid(obj), arg) );

}
else if (arg=="xiaoyao")
{
obj->set_skill("beiming-shengong",105);
obj->set_skill("bahuang-gong",105);
obj->set("tforceok",1);
	log_file("static/ZS",
		sprintf("%s Ҫ�ڹ�������: %s\n", geteuid(obj), arg) );

}
else if (arg=="riyue")
{
obj->set_skill("kuihua-xinfa",105);
obj->set_skill("tmdafa",105);
obj->set("tforceok",1);
	log_file("static/ZS",
		sprintf("%s Ҫ�ڹ�������: %s\n", geteuid(obj), arg) );

}

else if (arg=="taohua")
{
obj->set_skill("bibo-shengong",105);
obj->set("tforceok",1);
	log_file("static/ZS",
		sprintf("%s Ҫ�ڹ�������: %s\n", geteuid(obj), arg) );

}
else if (arg=="tiandihui")
{
obj->set_skill("yunlong-shengong",105);
obj->set("tforceok",1);
	log_file("static/ZS",
		sprintf("%s Ҫ�ڹ�������: %s\n", geteuid(obj), arg) );

}
else if (arg=="gumu")
{
obj->set_skill("yunv-xinfa",105);
obj->set("tforceok",1);
	log_file("static/ZS",
		sprintf("%s Ҫ�ڹ�������: %s\n", geteuid(obj), arg) );

}
else if (arg=="gaibang")
{
obj->set_skill("huntian-qigong",105);
obj->set("tforceok",1);
	log_file("static/ZS",
		sprintf("%s Ҫ�ڹ�������: %s\n", geteuid(obj), arg) );

}
else if (arg=="quanzhen")
{
obj->set_skill("xiantian-qigong",105);
obj->set("tforceok",1);
	log_file("static/ZS",
		sprintf("%s Ҫ�ڹ�������: %s\n", geteuid(obj), arg) );

}
else if (arg=="dali")
{
obj->set_skill("kurong-changong",105);
obj->set("tforceok",1);
	log_file("static/ZS",
		sprintf("%s Ҫ�ڹ�������: %s\n", geteuid(obj), arg) );

}
else if (arg=="tiezhang")
{
obj->set_skill("guiyuan-tunafa",105);
obj->set("tforceok",1);
	log_file("static/ZS",
		sprintf("%s Ҫ�ڹ�������: %s\n", geteuid(obj), arg) );

}
else if (arg=="murong")
{
obj->set_skill("shenyuan-gong",105);
obj->set("tforceok",1);
	log_file("static/ZS",
		sprintf("%s Ҫ�ڹ�������: %s\n", geteuid(obj), arg) );

}
else if (arg=="kunlun")
{
obj->set_skill("xuantian-wuji",105);
obj->set("tforceok",1);
	log_file("static/ZS",
		sprintf("%s Ҫ�ڹ�������: %s\n", geteuid(obj), arg) );

}
else if (arg=="lingxiao")
{
obj->set_skill("bingxue-xinfa",105);
obj->set("tforceok",1);
	log_file("static/ZS",
		sprintf("%s Ҫ�ڹ�������: %s\n", geteuid(obj), arg) );

}
else if (arg=="wdjiao")
{
obj->set_skill("wudu-shengong",105);
obj->set("tforceok",1);
	log_file("static/ZS",
		sprintf("%s Ҫ�ڹ�������: %s\n", geteuid(obj), arg) );

}
else if (arg=="emei")
{
obj->set_skill("linji-zhuang",105);
obj->set("tforceok",1);
	log_file("static/ZS",
		sprintf("%s Ҫ�ڹ�������: %s\n", geteuid(obj), arg) );

}
else if (arg=="xingxiu")
{
obj->set_skill("huagong-dafa",105);
obj->set("tforceok",1);
	log_file("static/ZS",
		sprintf("%s Ҫ�ڹ�������: %s\n", geteuid(obj), arg) );

}
else if (arg=="shenlong")
{
obj->set_skill("shenlong-xinfa",105);
obj->set("tforceok",1);
	log_file("static/ZS",
		sprintf("%s Ҫ�ڹ�������: %s\n", geteuid(obj), arg) );

}
else if (arg=="baituo")
{
obj->set_skill("hamagong",105);
obj->set("tforceok",1);

	log_file("static/ZS",
		sprintf("%s Ҫ�ڹ�������: %s\n", geteuid(obj), arg) );
}
else if (arg=="tangmen")
{
obj->set_skill("biyun-xinfa",105);
obj->set("tforceok",1);
	log_file("static/ZS",
		sprintf("%s Ҫ�ڹ�������: %s\n", geteuid(obj), arg) );

}
else if (arg=="feitian")
{
obj->set_skill("shayi-xinfa",105);
obj->set("tforceok",1);
	log_file("static/ZS",
		sprintf("%s Ҫ�ڹ�������: %s\n", geteuid(obj), arg) );

}
else
command("say �������кܶ����ڹ����ֱ�Ϊ
\t\t�䵱��\t\t(wudang)
\t\t��ɽ��\t\t(huashan)
\t\t���չ�\t\t(lingjiu)
\t\t�һ���\t\t(taohua)
\t\t��ػ�\t\t(tiandihui)
\t\t����\t\t(mingjiao)
\t\t��Ĺ��\t\t(gumu)
\t\tؤ��\t\t(gaibang)
\t\tȫ���\t\t(quanzhen)
\t\t����\t\t(dali)
\t\t���ư�\t\t(tiezhang)
\t\tĽ������\t(murong)
\t\t������\t\t(kunlun)
\t\t������\t\t(lingxiao)
\t\t�嶾��\t\t(wdjiao)
\t\t������\t\t(shaolin)
\t\t������\t\t(emei)
\t\t������\t\t(xingxiu)
\t\t������\t\t(shenlong)
\t\t����ɽ\t\t(baituo)
\t\t����\t\t(tangmen)
\t\t����������\t(feitian)
\t\tѩɽ��\t\t(xueshan)
\t\t��ң��\t\t(xiaoyao)
\t\t�������\t(riyue)
����Ҫ��һ���ڹ�Ϊ������");
    "/cmds/usr/save"->main(obj);
if (!wizardp(obj))
obj->start_busy(8);
    return 1;
}

int ask_force2()
{
    int i,temp,j;
    object obj;

obj=this_player();

if (obj->is_busy())
{
command("say ����æ����!");
        return notify_fail("����æ����!\n");
}
    if (obj->is_fighting()) 
        return notify_fail("���������������!\n");    

    if ( !userp(obj))
        return notify_fail("�ⲻ����Ұ�?\n");


command("say �������кܶ����ڹ����ֱ�Ϊ
\t\t�䵱��\t\t(wudang)
\t\t��ɽ��\t\t(huashan)
\t\t���չ�\t\t(lingjiu)
\t\t�һ���\t\t(taohua)
\t\t��ػ�\t\t(tiandihui)
\t\t����\t\t(mingjiao)
\t\t��Ĺ��\t\t(gumu)
\t\tؤ��\t\t(gaibang)
\t\tȫ���\t\t(quanzhen)
\t\t����\t\t(dali)
\t\t���ư�\t\t(tiezhang)
\t\tĽ������\t(murong)
\t\t������\t\t(kunlun)
\t\t������\t\t(lingxiao)
\t\t�嶾��\t\t(wdjiao)
\t\t������\t\t(shaolin)
\t\t������\t\t(emei)
\t\t������\t\t(xingxiu)
\t\t������\t\t(shenlong)
\t\t����ɽ\t\t(baituo)
\t\t����\t\t(tangmen)
\t\t����������\t(feitian)
\t\tѩɽ��\t\t(xueshan)
\t\t��ң��\t\t(xiaoyao)
\t\t�������\t(riyue)
����(yaoforce)Ҫ��һ���ڹ�Ϊ������");
if (!wizardp(obj))
obj->start_busy(8);
    return 1;
}

int ask_zs3()
{
    int i,temp;
    object obj;
mapping hp_status, skill_status, map_status, prepare_status;
mapping my;
string *sname, *mname, *pname;

obj=this_player();

    if (obj->is_fighting()) 
        return notify_fail("���������������!\n");    

     if(obj->is_busy())
        return notify_fail("��������æ��û��ɱ�ˡ�\n");

    if ( !userp(obj))
        return notify_fail("�ⲻ����Ұ�?\n");

    if (!obj->query("4zhuan")
    && !obj->query("5zhuan"))
{
command("say ��û���ʸ�Ҫ����!");
        return notify_fail("����û���ʸ�Ҫ����\n");
}
    if ( (int)obj->query("combat_exp") < 800000)
{
command("say �㾭��ߵ�����Ҫ��!");
        return notify_fail("�㾭��ߵ�����Ҫ��!\n");
}
    if ( (int)obj->query("max_neili") < 1000)
{
command("say ��û���ʸ�ת��!�����������!!");
        return notify_fail("����û���ʸ�ת��!\n");
}
if (obj->query("4zhuan",1) || obj->query("5zhuan",1))
{
obj->set_skill("tianrenheyi",105);
write(HIY"����书�����˺�һ��!\n"NOR);
}

if (obj->query("zhuanfinal/7",1)==1)
{
obj->set_skill("yinyang-shiertian",105);
write(HIY"����书������ʮ�����졿!\n"NOR);
}
if (obj->query("zhuanfinal/8",1)==1)
{
obj->set_skill("never-defeated",105);
write(HIY"����书�������񹦡�!\n"NOR);
}
    write(HIR"���ܻ�óɹ�!\n"NOR);
tell_object(obj,HIR"���ܻ�óɹ�!\n"NOR);
    return 1;
}


int ask_zs4()
{
    int i,temp,maxexp;
    object obj;
mapping hp_status, skill_status, map_status, prepare_status;
mapping my;
string *sname, *mname, *pname;

obj=this_player();

    if (obj->is_fighting()) 
        return notify_fail("���������������!\n");    

     if(obj->is_busy())
        return notify_fail("��������æ���ء�\n");

    if ( !userp(obj))
        return notify_fail("�ⲻ����Ұ�?\n");

    if (!obj->query("4zhuan")
    && !obj->query("5zhuan"))
{
command("say �㲻��ҪҪ��óɳ�����!");
        return notify_fail("���˲���ҪҪ��óɳ�����\n");
}
    if ( (int)obj->query("combat_exp") < 590000)
{
command("say �㾭��ߵ�����Ҫ��!");
        return notify_fail("�㾭��ߵ�����Ҫ��!\n");
}
    if ( (int)obj->query("max_neili") < 1000)
{
command("say ��û���ʸ�ת��!�����������!!");
        return notify_fail("����û���ʸ�ת��!\n");
}

    if ( (int)obj->query_temp("menpaijob",1) < 12)
{
command("say �㻹û������12������������!!");
        return notify_fail("�㻹û������12������������!!\n");
}

maxexp=6000000+(obj->query("expmax",1)*500000);

    if ( (maxexp-(int)obj->query("combat_exp",1)) > 800000)
{
command("say ��û�дﵽ�ɳ�ƿ����������!");
        return notify_fail("��û�дﵽ�ɳ�ƿ����������!\n");
}


if (obj->query_temp("menpaijob",1) >= 12)
{
if (obj->query("expmax",1) < 1)
{
obj->set("expmax",1);
}
else
{
obj->add("expmax",1);
}
}
obj->set_temp("menpaijob",0);
tell_object(obj,HIR"�ɳ�������óɹ�!\n"NOR);
    return 1;
}



