#include <ansi.h>
int do_copy(object me);
int do_back(object me);
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

#include <ansi.h>
void away();

void create()
{
   string weapon;
   int i = random(sizeof(names));
  set_name(names[i]+nm2[random(sizeof(nm2))]+nm3[random(sizeof(nm3))], ({"baobiao"}));
        set("nickname", HIG"����"NOR);
//        set_name("������ʿ", ({ "xia shi","xia","shi" }));
        set("gender", "����");
        set("age", 22);
        set("long", 
                "����һ��Ӣ���������ˣ������������������ƺ���һ��СС���֡�\n");
        set("attitude", "peaceful");
        set("age", random(10) + 25);
        set("no_quest", 1);
        set("str", 33);
        set("con", 26);
        set("int", 20);
        set("dex", 60);
        set("combat_exp", 1080000 + random(4000000)); 
        set("attitude", "friendly");
        set_skill("force", 50);
        set_skill("sword", 50);
        set_skill("dodge", 50);
        set_skill("parry", 50);
     set_skill("jiuyang-shengong", 100);
    set_skill("qiankun-danuoyi", 100);
    set_skill("qishang-quan", 100);
    set_skill("shenghuo-shengong", 100);
    set_skill("taiji-quan",150);
    set_skill("taiji-jian",150);
    set_skill("taiji-dao",150);
    set_skill("shenghuo-ling",300);

    map_skill("force", "shenghuo-shengong");
    map_skill("dodge", "qiankun-danuoyi");
    map_skill("unarmed", "qishang-quan");
    map_skill("cuff", "qishang-quan");
    map_skill("hand", "taiji-quan");
    map_skill("sword","shenghuo-ling");
    map_skill("parry","shenghuo-ling");
    map_skill("blade","taiji-dao");
        set("max_qi", 1450); 
        set("eff_jingli", 1400); 
        set("neili", 1700); 
        set("max_neili", 1700);
        set("jiali", 30);
        set("chat_chance_combat", 30);
        set("chat_msg_combat", ({
                (: perform_action, "sword.duo" :),
                (: perform_action, "sword.tougu" :),
                (: perform_action, "sword.xiyanling" :),
                (: perform_action, "sword.yinfeng" :),                
                (: command("unwield jian") :),
                (: command("unwield jian") :),
                (: command("wield jian") :),
                (: command("wield jian") :),
                (: perform_action, "cuff.hunpofeiyang" :),                
                (: perform_action, "cuff.youyouhunduan" :),                
                (: perform_action, "cuff.hunpofeiyang" :),                
                (: perform_action, "cuff.youyouhunduan" :),                
                (: perform_action, "dodge.canghaiyixiao" :),                                
                (: perform_action, "dodge.canghaiyixiao" :),                                
        }) );
        weapon = "/clone/weapon/gangjian";
        setup();
        carry_object(weapon)->wield();
        carry_object("/clone/cloth/cloth")->wear();
}


int checking(object ob, object me)
{
	if(!me || !present(me, environment())) do_back(ob);
	else call_out("checking", 2, ob, me);
        return 1;
}

int do_copy(object me)
{
        int i;
        object ob;
        ob = this_object();

      if(!me->query_temp("xx_rob")){
      	   do_back(me);
      	   return 0;
      	   }
        message_vision(HIR"ͻȻ�Ӹ����ܳ�һ��$N��������˵��������$n��\n"NOR, ob, me);
        me->add_temp("biaoshi", 1);
        
        ob->set("combat_exp",me->query("combat_exp") * 4 / 5);
        ob->set("max_qi",me->query("max_qi") * 3 / 4);
        ob->set("eff_qi",me->query("max_qi") * 3 / 4);
        ob->set("qi",me->query("max_qi") * 3 / 4);
        ob->set("max_jing",me->query("max_jing") * 3 / 4);
        ob->set("eff_jing",me->query("max_jing") * 3 / 4);
        ob->set("jing",me->query("max_jing") * 3 / 4);

        ob->set("max_jingli",me->query("max_jingli") * 3 / 4);
        ob->set("eff_jingli",me->query("max_jingli") * 3 / 4);
        ob->set("jingli",me->query("max_jingli") * 3 / 4);
        ob->set("max_neili",me->query("max_neili") * 3 / 4);
        ob->set("neili",me->query("max_neili") * 3 / 4);
        if (ob->query_skill("force")>5)
{
        ob->set_skill("force", me->query_skill("force"));
        ob->set_skill("jiuyang-shengong", me->query_skill("force")* 2 / 4);
        ob->set_skill("qiankun-danuoyi", me->query_skill("force")* 2 / 4);
        ob->set_skill("qishang-quan", me->query_skill("force")* 2 / 4);
        ob->set_skill("shenghuo-shengong",me->query_skill("force")* 2 / 4);
        ob->set_skill("dodge", me->query_skill("force")* 2 / 4); 
        ob->set_skill("sword", me->query_skill("force")* 2 / 4); 
        ob->set_skill("taiji-quan", me->query_skill("force")* 2 / 4); 
        ob->set_skill("parry",me->query_skill("force")* 2 / 4); 
        ob->set_skill("shenghuo-ling", me->query_skill("force")* 2 / 4);
}

        if (ob->query_skill("force")>5)
{
if (random(10)>8)
{
        ob->set_skill("force", me->query_skill("force"));
        ob->set_skill("jiuyang-shengong", me->query_skill("force")* 3 / 4);
        ob->set_skill("qiankun-danuoyi", me->query_skill("force")* 3 / 4);
        ob->set_skill("qishang-quan", me->query_skill("force")* 3 / 4);
        ob->set_skill("shenghuo-shengong",me->query_skill("force")* 3 / 4);
        ob->set_skill("dodge", me->query_skill("force")* 3 / 4); 
        ob->set_skill("sword", me->query_skill("force")* 3 / 4); 
        ob->set_skill("taiji-quan", me->query_skill("force")* 3 / 4); 
        ob->set_skill("parry",me->query_skill("force")* 3 / 4); 
        ob->set_skill("shenghuo-ling", me->query_skill("force")* 3 / 4);
}
}
        ob->kill_ob(me);
	 me->kill_ob(ob);
        checking(ob, me);    
        call_out("do_back", 350,  ob);  
        return 1;
}

int do_back(object me)
{
        object ob = this_object();
        if (!ob->is_fighting()) {
                message_vision(HIC "�������˳�ȥ�������ˡ�\n" NOR,this_object());
                destruct(this_object());
                }
}
void init()
{
        remove_call_out("leave");
        call_out("leave",350);
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
