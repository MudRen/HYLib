#include <ansi.h>
inherit NPC;
int do_copy(object me,int maxpot,int type);
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
//        set_name("��������", ({ "wokou", "japan wokou" }) );
        set("long",
"һ����ߴ����������˰̼Ӻ�����ɹ��ˡ�\n");
        set("attitude", "aggressive");
        set("attitude", "friendly");
//	set("nickname",HIR"�ɹ�Ԫʦ"NOR);
  set("force_factor",2+random(1390));
  set("max_qi",300+random(1690));
  set("max_jing",300+random(1890));
  set("max_sen",300+random(1890));
  set("max_neili",300+random(1890));
  set("max_mana",300+random(1890));
  set("eff_neili",300+random(1190));
  set("neili",300+random(1390));
        set("per", 1);
        set("age", 22);
        set("shen", -10000);
        set("intellgent",1);
	set("pursuer",1);
        set("combat_exp", 400000+random(900000));
	set("bellicosity", 0);
        set("chat_chance_combat", 40);
        set("chat_msg_combat", ({
                (: perform_action, "blade.leitingpili" :),
                (: perform_action, "blade.kuang" :),
                (: perform_action, "blade.kuang" :),
                (: perform_action, "strike.bashi" :),
                (: perform_action, "strike.bashi" :),
                (: perform_action, "finger.lingkong" :),
                (: perform_action, "finger.lingkong" :),
        }) );
        
        set_skill("unarmed", 80+random(180));
        set_skill("blade", 80+random(180));
        set_skill("parry", 80+random(180));
        set_skill("dodge", 180+random(180));
        set_skill("kuang-blade", 80+random(180));
        set_skill("jinding-zhang", 100);
        set_skill("tiangang-zhi", 100);
        set_skill("zhutian-bu", 100);
        set_skill("linji-zhuang", 100);

        
        map_skill("blade", "kuang-blade");
        map_skill("parry", "kuang-blade");
        map_skill("force","linji-zhuang");
        map_skill("finger","tiangang-zhi");
        map_skill("dodge","zhutian-bu");
        map_skill("strike","jinding-zhang");

        set_temp("apply/attack", 10);
        set_temp("apply/defense",10);
        set_temp("apply/armor", 10);
        set_temp("apply/damage", 50);

        setup();

        carry_object(__DIR__"obj/japancloth")->wear();
        carry_object(__DIR__"obj/japanblade")->wield();
}
void init()
{
	::init();
        remove_call_out("leave");
        call_out("leave",30);
}

void leave()
{
        object ob = this_object();
        if (!ob->is_fighting()) {
                message_vision(HIC "�ɹű����˳�ȥ�������ˡ�\n" NOR,this_object());
                destruct(this_object());
                }
        else call_out("leave",15);
}
int do_copy(object me,int maxpot,int type)
{
        int i,j;
        object ob;
        ob = this_object();
        i=me->query_skill("force",1);
//        if(type==1)
//		i = i - random(20);
//		else  
//	    i = i +10+ random(10);
//        if( i < 100) i = 100;
        
        ob->set("combat_exp", (me->query("combat_exp")*3/4));
        ob->set_skill("force", i*1/2);
        ob->set_skill("sword", i*1/2);
        ob->set_skill("cuff",  i*1/2);
	ob->set_skill("blade", i*1/2);
        ob->set_skill("dodge", i*1/2);
        ob->set_skill("parry", i*1/2);
        ob->set_skill("unarmed", i*1/2);
        ob->set_skill("kuang-blade", i*1/2);       
        ob->set_skill("zhutian-bu", i*1/2); 
        ob->set_skill("jinding-zhang", i*1/2); 
        ob->set_skill("linji-zhuang", i*1/2);         
        set_skill("linji-zhuang",i);
if (random(20)>18)
{
        ob->set_skill("force", i*3/4);
        ob->set_skill("sword", i*3/4);
        ob->set_skill("cuff",  i*3/4);
	ob->set_skill("blade", i*3/4);
        ob->set_skill("dodge", i*3/4);
        ob->set_skill("parry", i*3/4);
        ob->set_skill("unarmed", i*3/4);
        ob->set_skill("kuang-blade", i*4/4);       
        ob->set_skill("zhutian-bu", i*3/4); 
        ob->set_skill("jinding-zhang", i*3/4); 
        ob->set_skill("linji-zhuang", i*3/4);         
        set_skill("linji-zhuang",i);
}
if (me->query("combat_exp") >3500000)
{
        set("chat_chance_combat", 60);
        set("chat_msg_combat", ({
                (: perform_action, "blade.leitingpili" :),
                (: perform_action, "blade.kuang" :),
                (: perform_action, "strike.bashi" :),
                (: perform_action, "finger.lingkong" :),
        }) );
}

	ob->set("max_qi",  me->query("qi")*3/4); 
        ob->set("eff_jingli", me->query("eff_jingli")*3/4); 
        ob->set("max_neili", me->query("max_neili")*3/4); 
        ob->set("jiali", i/20);
        if(type==3)
		{ob->set("max_qi",     me->query("qi")*3/4);
		 ob->set("max_neili",  me->query("max_neili")*3/4); 
		}
		if(type==2)
        ob->set("max_qi",     me->query("qi")*3/4); 
		ob->reincarnate(); 
        ob->set("qi",ob->query("max_qi")*3/4);
        ob->set("neili",ob->query("max_neili")*3/4);
	    return 1;
}



void die()
{
int i,pot,exp;
	object killer;
	exp= random(80)+80;
	pot= exp*2/3;
	if(objectp(killer = query_temp("last_damage_from")))
        	tell_object(killer,"�㱻������\n"+chinese_number(exp)+"��ʵս����\n"
		+chinese_number(pot)+"��Ǳ��\n");
	killer->add("combat_exp",exp);
	killer->add("potential",pot);
	::die();

return ;
}
