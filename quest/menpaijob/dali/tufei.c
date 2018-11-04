#include <ansi.h>
inherit NPC;

string* names = ({
"��","Ǯ","��","��","��","��","֣","��","��","��","��","��",
"��","��","��","��","��","��","��","��","��","��","ʩ","��",
"��","��","��","��","��","κ","��","��","��","л","��","��",
"��","ˮ","�","��","��","��","��","��","��","��","��","��",
"³","Τ","��","��","��","��","��","��","ɵ","��","Ԭ","��",
"��","��","ʷ","��","��","��","�","Ѧ","��","��","��","��",
"��","��","��","��","��","��","��","��","��","��","ʱ","��",
"Ƥ","��","��","��","��","��","Ԫ","��","��","ӯ","ƽ","��",
"��","��","Ф","��","Ҧ","��","տ","��","��","ë","��","��",
"��","��","��","��","��","��","��","��","̸","��","é","��",
"��","��","��","��","��","ף","��","��","��","��","��","��",
"��","��","֧","��","��","��","¬","Ӣ","��","��","��","˧",
"˾��","�Ϲ�","ŷ��","�ĺ�","���","����","����","����","�ʸ�",
"ξ��","����","�̨","����","����","���","����","����","̫��",
"����","����","����","ԯ��","���","����","����","����","Ļ��",
"˾ͽ","ʦ��","��","��ľ","����","����","���","����","����",
"����","��ֺ","�й�","�׸�","����","����","�ַ�","��۳","Ϳ��",
"��ǧ","����","����","�Ϲ�","����","�麣","����","΢��","����",
"����","����","����","����","�Ϲ�",
"��","��","��","��","��","��","��","Ĳ","��","��","ī","��",
"��","��","��","��","١","��","��","��","��","��","��","��",
"��","ʯ",
});

string* ids = ({
"zhao","qian","sun","li","zhou","wu","zhen","wang","feng","chen","zhu","wei",
"jiang","shen","han","yang","zhu","qing","you","xu","he","lu","shi","zhang",
"kong","cao","yan","hua","jin","wei","tao","jiang","qie","xie","zhou","yu",
"bo","shui","dou","zhang","yun","su","pan","ge","xi","fan","peng","lang",
"lu","wei","chang","ma","miao","feng","hua","fang","sha","ren","yuan","liu",
"deng","bao","shi","tang","fei","lian","chen","xue","lei","he","ni","tang",
"teng","yin","luo","hua","hao","wu","an","chang","le","dai","shi","fu",
"pi","bian","qi","kang","wu","yu","yuan","po","gu","ying","ping","huang",
"he","mu","xiao","yin","yao","shao","zhan","wang","qi","mao","yu","di",
"mi","bei","ming","zang","ji","fu","cheng","dai","tan","song","mao","pang",
"xiong","ji","su","qu","xiang","zhu","dong","liang","fan","hu","ling","ho",
"yu","wan","zhi","ke","jiu","guan","lu","ying","qiu","hou","yue","suai",
"sima","shangguan","ouyang","xiahou","zhuge","wenren","dongfang","helian","huangpu",
"weichi","gongyang","zhantai","gongye","zongzheng","puyang","chunyu","shanyu","taishu",
"shentu","gongshun","zhongshun","xuanyuan","linghu","zhongli","yuwen","changshun","murong",
"situ","shikong","zhuankong","duanmu","wuma","gongxi","qidiao","lezheng","xiangsi",
"gongliang","tuozhi","jiagu","zaifu","guliang","chujing","yanfa","ruye","tuqin",
"duanqian","baili","dongguo","nanguo","huyan","guihai","yangshe","weisheng","liangqiu",
"zuoqiu","dongmen","ximen","baishang","nangong",
"gou","kang","kuang","hou","you","qing","shang","mo","she","er","mo","ha",
"qiao","nian","ai","yang","dong","di","wu","yan","fu","kai","zong","zong",
"lin","shi",
});
//----���»�ӭ��ӣ�nm2��Ҫһ���Ŀ��֣��Ա����������--------------
string* nm2 = ({
"��","Т","��","��","��","��","��","��","��","��","��","»","��","С","��",
"��","��","��","��","��","��","��","֮","��","��","ʱ","��","��","��","��",
"��","��","��","��","��","��","��","��","Ϊ","��","","","","","","","","",
"","","","","","","","","","","","","","",
});

string* nm3 = ({
"��","��","��","��","��","��","��","��","��","��","��","��",
"��","��","��","��","��","�","��","��","��","��","��",
"��","��","��","��","��","��","��","��","��","��","��",
"��","��","��","��","��","��","��","��","ǿ","��","ɽ",
"̩","��","ͦ","ΰ","��","��","��","��",
"��","�","��","��","��","��",
});

void create()
{
   int i = random(sizeof(names));
  set_name(names[i]+nm2[random(sizeof(nm2))]+nm3[random(sizeof(nm3))], ({ids[i]}));
    set("gender", "����" );//�Ա��������Ӧ
//       set("attitude", "aggressive");
        set("vendetta/authority",1);
  set("force_factor",2+random(1390));
  set("max_qi",600+random(1690));
  set("max_jing",600+random(1890));
  set("max_sen",600+random(1890));
  set("max_neili",600+random(1890));
  set("max_mana",600+random(1890));
  set("eff_neili",600+random(1390));
  set("neili",600+random(1390));
        set("per", 1);
        set("age", 22);
        set("shen", -10000);
        set("intellgent",1);
	set("pursuer",1);
        set("combat_exp", 400000+random(2000000));
	set("bellicosity", 10000);
        set("chat_chance_combat", 30);
        set("chat_msg_combat", ({
                (: perform_action, "sword.leitingpili" :),
                (: perform_action, "sword.kuang" :),
         }) );
        
        set_skill("unarmed", 80+random(180));
        set_skill("sword", 80+random(180));
        set_skill("parry", 80+random(180));
        set_skill("dodge", 180+random(180));
        set_skill("kuang-jian", 280+random(180));
        
        map_skill("sword", "kuang-jian");
        map_skill("parry", "kuang-jian");
        set_temp("apply/attack", 50);
        set_temp("apply/defense",100);
        set_temp("apply/armor", 120);
        set_temp("apply/damage", 50);

        setup();

        carry_object("clone/cloth/cloth")->wear();
        carry_object("clone/weapon/gangjian")->wield();
	add_money("silver", random(50));
}
void init()
{       
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("checking");
                call_out("checking", 0, ob);
        }
}

void checking(object ob)
{
        object me = this_object();
        int i;
//        object ob;
        ob = this_object();
//	mapping hp_status, skill_status, map_status, prepare_status;
//	string *sname, *mname, *pname;
//	int i, temp;

        if( !ob || !present(ob, environment(this_object())) || !present("biao yin", ob) ) {
                if(ob == query_leader() )       set_leader(0);
                return;
        }

        command("say "+ob->name()+"�����������£�������·����\n");
        set_leader(ob);

//        kill_ob(ob);
//        ob->fight_ob(me);
//        command("kill "+ob->query("id") );


        ob->set("str", me->query("str"));
        ob->set("dex", me->query("dex"));
        ob->set("per", me->query("per"));
        ob->set("qi", me->query("qi")* 3/4);
        ob->set("eff_qi", me->query("eff_qi")* 3/4);
        ob->set("jing", me->query("jing")* 3/4);
        ob->set("neili", me->query("neili")* 3/4);
        ob->set("max_neili", me->query("max_neili")* 3/4);
        ob->set("eff_jing", me->query("eff_jing")* 3/4);
if (me->query_skill("force",1)>10)
{
i=(int)me->query_skill("force",1);
        ob->set_skill("kuang-jian",i/2+120);
        ob->set_skill("sword",i/2);
        ob->set_skill("parry",i/2);        
}
        ob->set("combat_exp",me->query("combat_exp")* 3/4);
if(me->query_skill("kurong-changong",1)>40)
{
        ob->kill_ob(me);
        me->kill_ob(ob);
}
        ob->set_leader(me);
//        kill_ob(ob);
//        ob->fight_ob(me);

}

int heal_up()
{
        if( environment() && !is_fighting() ) {
                call_out("leave", 1);
                return 1;
        }
        return ::heal_up() + 1;
}

void leave()
{
        message("vision",HIB+name()+"����ææ���߿��ˡ�\n" NOR, 
                environment(), this_object() );
        destruct(this_object());
}

 void die()
{
        object ob, me, corpse;
int i,pot,exp;
	object killer;
	exp= random(30)+20;
	pot= exp*2/3;

	if(objectp(killer = query_temp("last_damage_from")))
        	tell_object(killer,"�㱻������\n"+chinese_number(exp)+"��ʵս����\n"
		+chinese_number(pot)+"��Ǳ��\n");

	killer->add("combat_exp",exp);
	killer->add("potential",pot);        
        ob = this_object();
message_vision("$N��ž����һ�����ڵ��ϣ���������˿��Ѫ��ʹ��������˼��¾����ˡ�\n", ob);
        destruct(ob);
        return;
}
