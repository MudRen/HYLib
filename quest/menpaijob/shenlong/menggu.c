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
      string weapon;
   int i = random(sizeof(names));
  set_name(names[i]+nm2[random(sizeof(nm2))]+nm3[random(sizeof(nm3))], ({ids[i]}));
	set("per", 35);
        set("gender", "����");
        set("long",
"һ����ߴ����������˰̼Ӻ���������\n");
         set("age", random(20) + 25);
        set("str", 23);
        set("con", 26);
        set("int", 20);
        set("dex", 23);
        set("combat_exp", 80000 + random(40000)); 
        set("attitude", "friendly");
        set_skill("xue-dao", 100-random(10));
        set_skill("unarmed",100-random(10));
        set_skill("xianglong-zhang",100-random(10));
        set_skill("dodge", 100-random(10));
        set_skill("blade", 100-random(10));
        set_skill("parry", 100-random(10));
        set_skill("dashou-yin", 100-random(10));
        set_skill("shenkong-xing", 100-random(10));
        set_skill("longxiang", 100-random(10));
        set_skill("huntian-qigong", 100-random(10));

        map_skill("force", "longxiang");
        map_skill("dodge", "shenkong-xing");
        map_skill("hand", "dashou-yin");
        map_skill("parry", "xue-dao");
        map_skill("blade", "xue-dao");
        map_skill("sword", "mingwang-jian");
        map_skill("unarmed","xianglong-zhang");

	set("chat_chance_combat", 50);  
	set("chat_msg_combat", ({
                (: perform_action, "blade.kuangdao" :),
                (: perform_action, "blade.shendao" :),
                (: perform_action, "blade.xueyu" :),
                (: perform_action, "blade.huan" :),
                (: perform_action, "blade.resurrect" :),
                (: perform_action, "blade.chi" :),
                (: perform_action, "blade.shi" :),
                (: perform_action, "blade.xue" :),
                (: perform_action, "blade.ying" :),                	
                (: perform_action, "dodge.tianmaxingkong" :),
                (: perform_action, "cuff.chen" :),
                (: perform_action, "cuff.jiang" :),
                (: perform_action, "hand.dashouyin" :),
                (: perform_action, "hand.jingang" :),
                (: perform_action, "hand.yin" :),             
                (: perform_action, "magic.ni" :),
                (: perform_action, "magic.hong" :),
                (: perform_action, "magic.ba" :),
                (: perform_action, "magic.an" :),              
                (: exert_function, "fumozhou" :),                
                (: exert_function, "fanchang" :),   
	}) );
        set("max_qi", 450); 
        set("eff_jingli", 400); 
        set("neili", 700); 
        set("max_neili", 700);
        set("jiali", 30);
        set_temp("apply/damage", 150);
        setup();
        carry_object("/clone/weapon/gangdao")->wield();
        carry_object("/clone/cloth/cloth")->wear();
}

int do_copy(object me,int maxpot,int type)
{
        int i,j;
        object ob;
        ob = this_object();
//me=this_player();
if (!me->query_skill("force"))
i=10;
else        i=me->query_skill("force",1);
//        if(type==1)
//		i = i - random(20);
//		else  
//	    i = i +10+ random(10);
//        if( i < 100) i = 100;
        
        ob->set("combat_exp", (me->query("combat_exp")*4/5));
ob->set("jing",me->query("max_jing"));
ob->set("eff_jing",me->query("max_jing"));
ob->set("max_jing",me->query("max_jing"));
ob->set("qi",me->query("max_qi"));
ob->set("eff_qi",me->query("max_qi"));
ob->set("max_qi",me->query("max_qi"));

        ob->set_skill("xue-dao", i*3/4+random(10));
        ob->set_skill("unarmed",i*3/4+random(10));
        ob->set_skill("xianglong-zhang",i*3/4+random(10));
        ob->set_skill("dodge", i*3/4+random(10));
        ob->set_skill("blade", i*3/4+random(10));
        ob->set_skill("parry", i*3/4+random(10));
        ob->set_skill("strike", i*3/4+random(10));
        ob->set_skill("dashou-yin", i*3/4+random(10));
        ob->set_skill("shenkong-xing", i*3/4+random(10));
        ob->set_skill("longxiang", i*3/4+random(10));
        ob->set_skill("huntian-qigong", i*3/4+random(10));
        ob->set_skill("dashou-yin",i*3/4+random(10));
        ob->set_skill("xiangmo-chu", i*3/4+random(10));
        ob->set_skill("magic", i*3/4+random(10));
        ob->set_skill("kwan-yin-spells", i*3/4+random(10));
ob->set_skill("mingwang-jian", i*3/4+random(10));
ob->set_skill("yujiamu-quan", i*3/4+random(10));
ob->set_skill("shenkong-xing", i*3/4+random(10));
ob->set_skill("lamaism", i*3/4+random(10));
ob->set_skill("xiangmo-chu", i*3/4+random(10));
ob->map_skill("magic", "kwan-yin-spells");
ob->map_skill("cuff", "yujiamu-quan");
ob->map_skill("hand", "dashou-yin");
ob->prepare_skill("cuff", "yujiamu-quan");
ob->prepare_skill("hand", "dashou-yin");
        ob->set_temp("apply/damage", 150);
        ob->set("eff_jingli", me->query("eff_jingli")*3/4); 
        ob->set("jiali", i/6);
	ob->set("max_qi",  me->query("qi")*2/3); 
        ob->set("eff_jingli", me->query("eff_jingli")*3/4); 
        ob->set("max_neili", me->query("max_neili")*3/4); 
        ob->set("jiali", i/10);
        if(type==3)
		{ob->set("max_qi",     me->query("qi")*3/43);
		 ob->set("max_neili",  me->query("max_neili")*3/4); 
		}
		if(type==2)
        ob->set("max_qi",     me->query("qi")*3/4); 
		ob->reincarnate(); 
        ob->set("qi",ob->query("max_qi")*3/4);
        ob->set("neili",ob->query("max_neili")*3/4);
}


void init()
{
        remove_call_out("leave");
        call_out("leave",120);
}

void leave()
{
        object ob = this_object();
        if (!ob->is_fighting()) {
                message_vision(this_object()->query("name") + "���·�ߵ��Ӳݣ������ˡ�\n" NOR,this_object());
                destruct(this_object());
                }
        else call_out("leave",30);
}
void die()
{
int i,pot,exp;
	object killer;
	exp= random(100)+150;
	pot= exp/3;
	if(objectp(killer = query_temp("last_damage_from")))
        	tell_object(killer,"�㱻������\n"+chinese_number(exp)+"��ʵս����\n"
		+chinese_number(pot)+"��Ǳ��\n");
	killer->add("combat_exp",exp);
	killer->add("potential",pot);
	::die();

return ;
}
