// yangguo.c ���
// By Kayin @ CuteRabbit Studio 99-4-16 21:10 new
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
	set("per", 35);
	set("gender", "����");
	set("age", 30);
	set("per",30);
	set("con",30);
	set("str", 30);
	set("class","gumu");
	set("dex", 30);
	set("long", "����һλ�ߴ�����ӣ���ò���㡣\n"+
	"��Ȼ�ڲ�ס�����˵ķ�ɡ�\n");
	set("combat_exp", 10000000);
	set("score", 10000);
	set("shen_type", 1);
	set("attitude", "peaceful");

	set_skill("sword", 350);
	set_skill("force", 400);
	set_skill("unarmed", 400);
	set_skill("dodge", 350);
	set_skill("parry", 350);
	set_skill("anranxiaohun-zhang",360);
	set_skill("xuantie-sword", 300);
	set_skill("xiantian-qigong", 100);
	set_skill("yunv-shenfa",300);
	set_skill("yunv-xinfa",320);
	map_skill("force", "yunv-xinfa");
	map_skill("sword", "xuantie-sword");
	map_skill("parry", "anranxiaohun-zhang");
	map_skill("unarmed","anranxiaohun-zhang");
	map_skill("dodge", "yunv-shenfa");
	set("chat_chance_combat", 40);
       set("chat_msg_combat", ({
                (: perform_action, "parry.xiaohun" :),
                (: perform_action, "sword.feihongrudian" :),
                
        }) );
	set_temp("apply/attack", 200);
	set_temp("apply/defense", 100);
	set_temp("apply/armor", 240);
	set_temp("apply/damage", 200);
	set("neili", 15000); 
	set("max_neili", 15000);
	set("max_qi", 10000);
	set("qi",10000);
       create_family("��Ĺ��", 3, "��ʦ����");
        set("chat_chance", 60);
        set("chat_msg", ({
                (: random_move :),
        }) );
	setup();
	carry_object("/clone/misc/cloth")->wear();
	carry_object("d/gumu/npc/obj/tiesword")->wield();
//	carry_object("clone/weapon/gangjian")->wield();
	add_money("gold", 2);
}


void die()
{
        object ob, me, corpse;
        ob = this_object();
        me = query_temp("last_damage_from");
        
if (me)
{
        if (userp(me))
{
if (me->query("family/family_name")!= ob->query("family/family_name")){message("vision", me->name() + "������300�����200Ǳ�ܡ�\n", me);
        
        
        message("vision", me->name() + "������300�����200Ǳ�ܡ�\n", me);
        me->add("combat_exp",300);
        me->add("potential",200);
        me->add("score",100);
        me->add("shen",100);
        }destruct(ob);
        return;
}
}
}
#include "heimuya_job.h";