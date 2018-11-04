// shi.c ʷ��ɽ
#include <ansi.h> 
inherit NPC;
string ask_me();
void create()
{
	set_name("ʷ��ɽ", ({ "shi qingshan", "shi" }));
	set("title", "�����ؽ�");
	set("gender", "����");
	set("age", 33);
	set("str", 25);
	set("dex", 16);
	set("long", "ʷ��ɽ�������䵱ɽ���׼ҵ��ӣ���֪Ϊ�γ����˳�͢����\n");
	set("combat_exp", 400000);
	set("shen", 4000);
	set("attitude", "heroism");

	set_skill("unarmed", 70);
	set_skill("force", 120);
	set_skill("sword", 120);
	set_skill("dodge", 120);
        set_skill("yinyun-ziqi", 120);
        set_skill("taiji-quan", 120);
        set_skill("cuff", 120);
	set_skill("parry", 120);
	set_skill("taiji-jian", 120);
	map_skill("parry", "taiji-jian");
	map_skill("sword", "taiji-jian");
        map_skill("cuff", "taiji-quan");
        prepare_skill("cuff", "taiji-quan");
	set_temp("apply/attack", 20);
	set_temp("apply/defense", 20);
	set_temp("apply/armor", 20);
	set_temp("apply/damage", 20);
        set("inquiry", ([
              
                "Ϊ��" : (: ask_me :),
                "��Ч��͢" : (: ask_me :),
       ]));
	set("max_qi", 1000);
	set("neili", 1200); 
	set("max_neili", 1200);
        set("jiali", 20);

	setup();
	carry_object(__DIR__"gangjian")->wield();
        carry_object(__DIR__"tiejia")->wear();
}

int accept_fight(object me)
{
	command("say �Ϸ��δ�ͽ����˶��ֹ����ˣ�����Ҳ����������");
	return 0;
}
string ask_me()
{        
       object ob, me;
       int gftimes;

       me = this_player();
       ob = this_player();
       gftimes = (int)ob->query("gf_job",1);
       
       if (gftimes<1)
       return "��λ"+RANK_D->query_respect(me)+"��û��Ϊ��͢����������̸�����أ���\n"; 
       if (gftimes>=1 && gftimes<50)
       return "��λ"+RANK_D->query_respect(me)+"Ŀǰ���Ͳ���������Ŭ���ɣ���\n"; 
       if (gftimes>=50 && gftimes<100){
       command("nod ");
       command("say ���ѽ���Ĺ��ͱ����˱������飬ǰ�ձ�������������Ϊ�첶��");
       me->set_temp("apply/short", ({HIY"��Ʒ�첶 "NOR+me->name()+"("+me->query("id")+")"}));
       return "�ұ������������Ϊ���ҳ�����Ϊ�����츣����\n"; 
       }
       if (gftimes>=100 && gftimes<200){
       command("nod " + me->query("id"));
       command("say ���ѽ���Ĺ��ͱ����˱������飬ǰ�ձ�������������Ϊ��ͷ��");
       me->set_temp("apply/short", ({HIY"��Ʒ��ͷ "NOR+me->name()+"("+me->query("id")+")"}));
       return "�úøɣ��Ϸ��ǲ��������ģ�\n";
       }
       if (gftimes>=200 && gftimes<500){
       command("pat " + me->query("id"));
       command("say ��λ"+RANK_D->query_respect(me)+"�Ĺ������Դ��ߴ��С��ش�������Ϊ������");
       me->set_temp("apply/short", ({HIY"��Ʒ���� "NOR+me->name()+"("+me->query("id")+")"}));
       return "��λ"+RANK_D->query_respect(me)+"�Ĺ��Ͳ�С���Ϸ��´ν�����һ��Ҫ��������������飡\n";
       }
       if (gftimes>=500 && gftimes<1000){
       command("thumb " + me->query("id"));
       me->set_temp("apply/short", ({HIY"��Ʒ��˾ "NOR+me->name()+"("+me->query("id")+")"}));
       return "��λ"+RANK_D->query_respect(me)+"�ĳɼ���С������Ҫ�ͽ������˴�Ļ��ȣ������ݹ��Ϸ��������飡\n";
       }
       if (gftimes>=500 && gftimes<1000){
       command("haha " + me->query("id"));
       command("say ��λ"+RANK_D->query_respect(me)+"���书���Ǿ�Ϊ������һ������Ŭ���ɣ�");
       me->set_temp("apply/short", ({HIY"��Ʒ�λ� "NOR+me->name()+"("+me->query("id")+")"}));
       return "��˵������ϳ��н�������û����ȥ��鿴��\n";
       }
       if (gftimes>=1000 && gftimes<2000){
       me->set_temp("apply/short", ({HIY"��Ʒ�ν� "NOR+me->name()+"("+me->query("id")+")"}));
       return "�Ϸ��Ѱ�����Ϊ�ν����Ժ�����»ָ�տɴ���\n";
       }
       if (gftimes>=2000 && gftimes<2500){
       me->set_temp("apply/short", ({HIY"��Ʒ���� "NOR+me->name()+"("+me->query("id")+")"}));
       return "��˵����������Ҫ����ǰȥ���ǣ����Ժ�ǰ;Զ�󰡣�\n";
       }
       if (gftimes>2500){
       me->set_temp("apply/short", ({HIY"������ "NOR+me->name()+"("+me->query("id")+")"})); //wiz get it now
       return "���ᣬ����ѹ����ı��Ϸ򻹴�\n";
//       return "���ᣬ����ѹ����ı��Ϸ򻹴�\n";
       }
}
void kill_ob(object me)
{
	command("say �󵨵��񣬾���ı����͢���٣�����\n");
//        me->apply_condition("killer", 100);
	::kill_ob(me);
}
 
