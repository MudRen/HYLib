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
   int temp;
   
   int i = random(sizeof(names));
   temp=random(80)+30;
  set_name(names[i]+nm2[random(sizeof(nm2))]+nm3[random(sizeof(nm3))], ({"weishi"}));
        set("nickname", HIG"��������"NOR);
//        set_name("������ʿ", ({ "xia shi","xia","shi" }));
        set("gender", "����");
        set("age", 22);
        set("long", 
                "����һ�����������������ֵ���\n");
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
        set_skill("unarmed", 80+random(180));
        set_skill("sword", 80+random(180));
        set_skill("parry", 80+random(180));
        set_skill("dodge", 180+random(180));
        set_skill("kuang-jian", 80+random(180));
       
    map_skill("force", "shenghuo-shengong");
    map_skill("dodge", "qiankun-danuoyi");
    map_skill("unarmed", "qishang-quan");
    map_skill("cuff", "qishang-quan");
    map_skill("hand", "taiji-quan");
    map_skill("sword","kuang-jian");
    map_skill("parry","kuang-jian");
    map_skill("blade","taiji-dao");
       set_skill("xue-dao", temp-random(10));
        set_skill("unarmed",temp-random(10));
        set_skill("xianglong-zhang",temp-random(10));
        set_skill("dodge", temp-random(10));
        set_skill("blade", temp-random(10));
        set_skill("parry", temp-random(10));
        set_skill("dashou-yin", temp-random(10));
        set_skill("shenkong-xing", temp-random(10));
        set_skill("longxiang", temp-random(10));
        set_skill("huntian-qigong", temp-random(10));

        set_skill("dashou-yin",temp-random(10));
        set_skill("xiangmo-chu", temp-random(10));
        set_skill("magic", temp-random(10));
        set_skill("kwan-yin-spells", temp-random(10));
set_skill("mingwang-jian", temp-random(10));
set_skill("yujiamu-quan", temp-random(10));
set_skill("shenkong-xing", temp-random(10));
set_skill("lamaism", temp-random(10));
set_skill("xiangmo-chu", temp-random(10));

        map_skill("force", "longxiang");
        map_skill("dodge", "shenkong-xing");
        map_skill("hand", "dashou-yin");
        map_skill("parry", "xue-dao");
        map_skill("blade", "xue-dao");
        map_skill("sword", "mingwang-jian");
        map_skill("unarmed","xianglong-zhang");

map_skill("magic", "kwan-yin-spells");
map_skill("cuff", "yujiamu-quan");
map_skill("hand", "dashou-yin");
prepare_skill("cuff", "yujiamu-quan");
prepare_skill("hand", "dashou-yin");
        set("max_qi", 1450); 
        set("eff_jingli", 1400); 
        set("neili", 1700); 
        set("max_neili", 1700);
        set("jiali", 30);
        map_skill("sword", "kuang-jian");
        map_skill("parry", "kuang-jian");
        set_temp("apply/attack", 20);
        set_temp("apply/defense",50);
        set_temp("apply/armor", 150);
        set_temp("apply/damage", 120);
	set("chat_chance_combat", 50);  
	set("chat_msg_combat", ({
                (: perform_action, "blade.kuangdao" :),                
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
        setup();
        carry_object("/clone/weapon/gangdao")->wield();
        carry_object("/clone/cloth/cloth")->wear();
}


int checking(object ob, object me)
{
	if(!me || !present(me, environment())) do_back(ob);
	else call_out("checking", 5, ob, me);
        return 1;
}

int do_copy(object me)
{
        int i,temp;
        object ob;
        ob = this_object();

      if(!me->query_temp("xx_rob")){
      	   do_back(me);
      	   return 0;
      	   }
        message_vision(HIR"ͻȻ�Ӵ��ϴܳ�һ��$N��������˵��������$n��\n"NOR, ob, me);
        me->add_temp("biaoshi", 1);
        
        ob->set("combat_exp",me->query("combat_exp") * 4 / 5);
        ob->set("max_qi",me->query("max_qi") * 3 / 4);
        ob->set("eff_qi",me->query("max_qi") * 3 / 4);
        ob->set("qi",me->query("max_qi") * 3 / 4);
        ob->set("max_jingli",me->query("max_jingli") * 3 / 4);
        ob->set("eff_jingli",me->query("max_jingli") * 3 / 4);
        ob->set("jingli",me->query("max_jingli") * 3 / 4);
        ob->set("max_neili",me->query("max_neili") * 3 / 4);
        ob->set("neili",me->query("max_neili") * 3 / 4);
        ob->set_skill("force", me->query_skill("force",1) * 3 / 4);
        ob->set("max_jing",me->query("max_jing") * 3 / 4);
        ob->set("eff_jing",me->query("max_jing") * 3 / 4);
        ob->set("jing",me->query("max_jing") * 3 / 4);
       temp=(int)me->query_skill("force",1)* 2 / 4;
       if (random(10)>8)temp=(int)me->query_skill("force",1)* 3 / 4;

       ob->set_skill("xue-dao", temp-random(10));
        ob->set_skill("unarmed",temp-random(10));
        ob->set_skill("xianglong-zhang",temp-random(10));
        ob->set_skill("dodge", temp-random(10));
        ob->set_skill("blade", temp-random(10));
        ob->set_skill("parry", temp-random(10));
        ob->set_skill("dashou-yin", temp-random(10));
        ob->set_skill("shenkong-xing", temp-random(10));
        ob->set_skill("longxiang", temp-random(10));
        ob->set_skill("huntian-qigong", temp-random(10));

        ob->set_skill("dashou-yin",temp-random(10));
        ob->set_skill("xiangmo-chu", temp-random(10));
        ob->set_skill("magic", temp-random(10));
        ob->set_skill("kwan-yin-spells", temp-random(10));
ob->set_skill("mingwang-jian", temp-random(10));
ob->set_skill("yujiamu-quan", temp-random(10));
ob->set_skill("shenkong-xing", temp-random(10));
ob->set_skill("lamaism", temp-random(10));
ob->set_skill("xiangmo-chu", temp-random(10));

        ob->map_skill("force", "longxiang");
        ob->map_skill("dodge", "shenkong-xing");
        ob->map_skill("hand", "dashou-yin");
        ob->map_skill("parry", "xue-dao");
        ob->map_skill("blade", "xue-dao");
        ob->map_skill("sword", "mingwang-jian");
        ob->map_skill("unarmed","xianglong-zhang");

ob->map_skill("magic", "kwan-yin-spells");
ob->map_skill("cuff", "yujiamu-quan");
        if (me->query_skill("force",1)>5)
{
        ob->set_skill("jiuyang-shengong", me->query_skill("force",1)* 2 / 4);
        ob->set_skill("qiankun-danuoyi", me->query_skill("force",1)* 2 / 4);
        ob->set_skill("qishang-quan", me->query_skill("force",1)* 2 / 4);
        ob->set_skill("shenghuo-shengong",me->query_skill("force",1)* 2 / 4);
        ob->set_skill("dodge", me->query_skill("force",1)* 2 / 4); 
        ob->set_skill("sword", me->query_skill("force",1)* 2 / 4); 
        ob->set_skill("taiji-quan", me->query_skill("force",1)* 2 / 4); 
        ob->set_skill("parry",me->query_skill("force",1)* 2 / 4); 
        ob->set_skill("shenghuo-ling", me->query_skill("force",1)* 2 / 4);
        ob->set_skill("kuang-jian", me->query_skill("force",1)* 2 / 4); 
}
        if (me->query_skill("force",1)>5)
{
if (random(10)>8)
{
        ob->set_skill("jiuyang-shengong", me->query_skill("force",1)* 3 / 4);
        ob->set_skill("qiankun-danuoyi", me->query_skill("force",1)* 3 / 4);
        ob->set_skill("qishang-quan", me->query_skill("force",1)* 3 / 4);
        ob->set_skill("shenghuo-shengong",me->query_skill("force",1)* 3 / 4);
        ob->set_skill("dodge", me->query_skill("force",1)* 3 / 4); 
        ob->set_skill("sword", me->query_skill("force",1)* 3 / 4); 
        ob->set_skill("taiji-quan", me->query_skill("force",1)* 3 / 4); 
        ob->set_skill("parry",me->query_skill("force",1)* 3 / 4); 
        ob->set_skill("shenghuo-ling", me->query_skill("force",1)* 3 / 4);
        ob->set_skill("kuang-jian", me->query_skill("force",1)* 3 / 4); 
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
                message_vision(this_object()->query("name") + "һ�����Ѿ��������������ʧ�ˡ�\n", this_object());
                destruct(this_object());
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
