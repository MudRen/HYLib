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
	set("per", 35);
    set("gender", "����");
    set("age", 42);
    set("long", 
        "���������ŵ�һ�����ӡ����ºö�ȫ�ɼ��ġ�\n");
    set("attitude", "peaceful");
    set("class", "scholar");
	
    set("str", 21);
    set("int", 30);
    set("con", 26);
    set("dex", 30);


    set("qi", 5000);
    set("max_qi", 5000);
    set("jing", 3000);
    set("max_jing", 3000);
    set("neili", 13500);
    set("max_neili", 13500);
    set("jiali", 100);

    set("book_count", 1);
    set("combat_exp", 2500000);
    set("score", 0);
	 
 		set_skill("zhuihun-biao", 380);
		set_skill("liuxing-biao", 380);
	set_skill("pili-biao",380);
	set_skill("force", 350);
	set_skill("biyun-xinfa", 380);
	set_skill("dodge", 350);
	set_skill("qiulinshiye", 380);
	set_skill("strike", 250);
	set_skill("unarmed",280);
	set_skill("biye-wu", 380);
	set_skill("parry", 280);
	set_skill("throwing", 380);
	set_skill("zimu-zhen", 380);
	set_skill("literate", 250);
	map_skill("force", "biyun-xinfa");
	map_skill("dodge", "qiulinshiye");
	map_skill("strike", "biye-wu");
	map_skill("unarmed","biye-wu");
	map_skill("parry", "zimu-zhen");
	map_skill("throwing", "zimu-zhen");
	
	create_family("����", 6, "��ʦ����");
	set("class", "tangmen");

	set("chat_chance_combat", 90);
	set("chat_msg_combat", ({
		(: perform_action, "throwing.poqizhen" :),
		(: perform_action, "throwing.dinhun" :),
                (: perform_action, "throwing.qizigangbiao" :),
                (: perform_action, "throwing.tanghua" :),
		(: perform_action, "strike.wandu" :),
		(: perform_action, "strike.meng" :),
		(: exert_function, "recover" :),
	}) );
        set_temp("apply/defense", 200);
        set_temp("apply/armor", 500);
        set_temp("apply/damage", 200);
        set_temp("apply/attack", 200);


    setup();
	
	carry_object("/d/tangmen/obj/zimuzhen")->wield();
	carry_object("/d/tangmen/obj/shujin")->wear();
   
}

int do_copy(object me,int maxpot,int type)
{
        int i,j;
        object ob;
        ob = this_object();
        i=maxpot;
        if(type==1)
		i = i - random(20);
		else  
	    i = i +10+ random(10);
        if( i < 100) i = 100;
        
ob->set("combat_exp", (me->query("combat_exp")));
        ob->set_skill("force", i);
        ob->set_skill("sword", i);
        ob->set_skill("staff", i);        
        ob->set_skill("cuff",  i);
	ob->set_skill("blade", i);
	ob->set_skill("hand", i);
	ob->set_skill("finger", i);
        ob->set_skill("dodge", i);
        ob->set_skill("parry", i);
        ob->set_skill("unarmed", i);
	ob->set("max_qi",  me->query("max_qi")); 
	ob->set("max_jing",  me->query("max_jing")); 
        ob->set("eff_jingli", me->query("eff_jingli")); 
        ob->set("max_neili",  me->query("max_neili")); 
        ob->set("jiali", i/5);
        if(type==3)
		{ob->set("max_qi",     i*30);
		 ob->set("max_neili",  i*15); 
		}
		if(type==2)
        ob->set("max_qi",     i*20); 
		ob->reincarnate(); 
        ob->set("qi",ob->query("max_qi"));
        ob->set("neili",ob->query("max_neili"));
	    return 1;
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
