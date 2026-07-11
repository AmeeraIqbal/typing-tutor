/*
============================================================
                     TYPING TUTOR SYSTEM
============================================================

Author      : Ameera Iqbal
Language    : C++
Course      : Programming Fundamentals
Semester    : 2nd Semester
Year        : 2026

Description:
This program allows users to improve their typing skills by
selecting a difficulty level and topic. A random sentence is
displayed, and the program calculates typing speed (WPM) and
provides performance feedback based on the user's accuracy.

============================================================
*/

//Header files
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;

//Main function
int main()
{
    // ======================= HISTORY SENTENCES =======================
    string history_easy[20] = {
        "The Roman Empire was very powerful",
        "Egypt had many great pharaohs",
        "The Great Wall of China is old",
        "Napoleon was a famous leader",
        "The Renaissance happened in Europe",
        "Vikings sailed across the sea",
        "The Silk Road connected Asia and Europe",
        "Cleopatra ruled Egypt long ago",
        "The Pyramids are in Egypt",
        "Alexander the Great was a king",
        "The Middle Ages lasted for centuries",
        "The Industrial Revolution changed the world",
        "Columbus sailed to America in 1492",
        "The French Revolution was important",
        "The Ottoman Empire was very large",
        "Sparta was a warrior city",
        "Rome was built on seven hills",
        "The Aztecs ruled Mexico",
        "The Byzantine Empire lasted long",
        "Machu Picchu was built by the Incas"
    };

    string history_medium[20] = {
        "The Roman Empire expanded across three continents",
        "Ancient Egypt developed complex irrigation systems",
        "The Great Wall of China served as military defense",
        "Napoleon revolutionized European military tactics",
        "The Renaissance marked revival of classical learning",
        "Viking exploration expanded knowledge of northern regions",
        "The Silk Road facilitated trade between civilizations",
        "Cleopatra was known for her political intelligence",
        "Egyptian pyramids showcase advanced engineering skills",
        "Alexander the Great conquered vast territories",
        "Medieval feudalism structured European society",
        "The Industrial Revolution transformed human labor",
        "Columbus voyage opened new trade routes",
        "French Revolution challenged absolute monarchy",
        "Ottoman Empire controlled Mediterranean trade routes",
        "Spartan warriors followed strict military discipline",
        "Roman aqueducts transported water across distances",
        "Aztec civilization achieved remarkable architectural feats",
        "Byzantine Empire preserved Greek and Roman knowledge",
        "Incan engineering created mountain city structures"
    };

    string history_advanced[20] = {
        "The Roman Empire's administrative structure enabled effective governance",
        "Ancient Egypt's hieroglyphic writing system represented phonetic and ideographic elements",
        "The Great Wall's construction reflected strategic military and geopolitical considerations",
        "Napoleon's legal reforms established the Napoleonic Code across Europe",
        "Renaissance humanism emphasized classical texts and individual achievement",
        "Viking maritime technology enabled unprecedented oceanic navigation",
        "The Silk Road's interconnected networks facilitated cultural and economic exchange",
        "Cleopatra's diplomatic negotiations maintained Egyptian independence against Rome",
        "Egyptian pyramid construction required advanced mathematical and organizational knowledge",
        "Alexander the Great's conquests created unprecedented cultural synthesis",
        "Medieval feudalism established hierarchical socioeconomic structures",
        "The Industrial Revolution's mechanization fundamentally altered production methods",
        "Columbus voyage initiated transatlantic contact with profound consequences",
        "French Revolution's egalitarian ideals challenged entrenched aristocratic privileges",
        "Ottoman Empire's administrative innovations influenced European governance",
        "Spartan military education system created disciplined warrior societies",
        "Roman engineering achievements established standards for infrastructure development",
        "Aztec civilization's complex calendar system demonstrated astronomical knowledge",
        "Byzantine Empire preserved intellectual heritage through manuscript copying",
        "Incan road network connected vast territories through engineered pathways"
    };

   // ======================= SCIENCE SENTENCES =======================
    string science_easy[20] = {
        "The sun gives us heat and light",
        "Plants need water and sunlight",
        "Animals eat food for energy",
        "The earth rotates around the sun",
        "Water can freeze into ice",
        "Lightning is very powerful electricity",
        "Gravity pulls objects to the ground",
        "Blood flows through our veins",
        "The moon orbits around the earth",
        "Oxygen is needed to breathe",
        "Stars shine at night in the sky",
        "Dinosaurs lived very long ago",
        "Magnets attract some metals",
        "Sound travels through the air",
        "Fire needs oxygen to burn",
        "The rainbow has many colors",
        "Atoms are very small particles",
        "Germs can make us sick",
        "Photosynthesis makes food in plants",
        "The ocean has many creatures"
    };

    string science_medium[20] = {
        "The sun's energy drives Earth's climate system",
        "Photosynthesis converts sunlight into chemical energy",
        "Cellular respiration breaks down glucose into energy",
        "Earth's rotation creates day and night cycles",
        "Phase changes between states depend on temperature",
        "Lightning results from electrical discharge in atmosphere",
        "Gravitational force depends on mass and distance",
        "Cardiovascular system distributes oxygen throughout body",
        "Lunar gravity influences Earth's oceanic tides",
        "Oxygen molecules are essential for aerobic respiration",
        "Stars emit light through nuclear fusion reactions",
        "Extinction events have shaped evolutionary history",
        "Electromagnetic force enables magnetic attraction",
        "Sound waves vibrate through different mediums",
        "Combustion requires fuel, oxygen, and heat",
        "Light refraction creates rainbow optical phenomena",
        "Atomic structure comprises protons, neutrons and electrons",
        "Microorganisms cause infectious diseases",
        "Chlorophyll molecules capture light energy",
        "Marine ecosystems support incredible biodiversity"
    };

    string science_advanced[20] = {
        "The sun's thermonuclear fusion processes generate electromagnetic radiation",
        "Photosynthetic pathways utilize light reactions and Calvin cycle mechanisms",
        "Mitochondrial respiration produces adenosine triphosphate through oxidative phosphorylation",
        "Earth's axial tilt and orbital mechanics determine seasonal variations",
        "Thermodynamic phase transitions involve energy transfer and entropy changes",
        "Lightning generation involves ionization cascades and stepped leaders",
        "Gravitational fields exhibit inverse square relationship with distance",
        "Cardiac physiology involves complex electromechanical coupling mechanisms",
        "Gravitational perturbations create lunar libration and tidal resonances",
        "Aerobic respiration employs electron transport chains efficiently",
        "Stellar nucleosynthesis creates heavier elements through fusion processes",
        "Mass extinction events correlate with environmental catastrophic changes",
        "Electromagnetic fields exhibit wave particle duality properties",
        "Acoustic phenomena involve frequency, wavelength and amplitude relationships",
        "Exothermic reactions release energy through chemical bond reorganization",
        "Light wavelength determines visible spectrum color perception",
        "Quantum mechanics governs atomic and subatomic particle behavior",
        "Pathogenic mechanisms involve virulence factors and host interactions",
        "Quantum photosynthesis involves coherent energy transfer mechanisms",
        "Benthic ecosystems support chemosynthetic and photosynthetic organisms"
    };

    // ====================== TECHNOLOGY SENTENCES =====================
    string technology_easy[20] = {
        "Computers help us work and play",
        "The internet connects people worldwide",
        "Smartphones are very useful devices",
        "Artificial intelligence is becoming common",
        "Robots can perform many tasks",
        "Coding is used to create programs",
        "Databases store large amounts of data",
        "Cloud computing stores files online",
        "Cybersecurity protects our information",
        "Mobile apps are on our phones",
        "The web browser helps us browse",
        "Algorithms solve computer problems",
        "Software runs on our devices",
        "Hardware is the physical computer",
        "Servers provide data to users",
        "Networks connect multiple computers",
        "Programming languages create instructions",
        "Encryption keeps our data safe",
        "Technology changes very quickly",
        "Digital transformation helps businesses"
    };

    string technology_medium[20] = {
        "Computers process information using binary codes",
        "Internet infrastructure uses packet switching technology",
        "Smartphones integrate multiple technologies into devices",
        "Artificial intelligence uses machine learning algorithms",
        "Robots employ sensors and actuators",
        "Programming requires logical problem solving skills",
        "Databases utilize relational or non-relational structures",
        "Cloud infrastructure provides scalable computing resources",
        "Cybersecurity implements multiple protective layers",
        "Mobile applications run on operating systems",
        "Web browsers render HTML and CSS code",
        "Algorithms determine computational efficiency and speed",
        "Software development follows structured methodologies",
        "Hardware components work together systematically",
        "Server architecture manages request responses",
        "Network protocols enable data transmission",
        "Programming paradigms include object oriented and functional",
        "Encryption algorithms protect sensitive information",
        "Technology adoption requires organizational change",
        "Digital transformation integrates technology into operations"
    };

    string technology_advanced[20] = {
        "Computational architecture employs von Neumann design principles",
        "Internet protocol suite enables decentralized data transmission",
        "Mobile computing integrates sensors, processors and communication modules",
        "Machine learning algorithms optimize through iterative parameter adjustment",
        "Robotics combines computer vision, kinematics and control systems",
        "Programming paradigms implement different computational abstractions",
        "Database normalization reduces redundancy and ensures consistency",
        "Cloud computing architecture utilizes virtualization and containerization",
        "Cybersecurity employs encryption, authentication and intrusion detection",
        "Mobile operating systems manage hardware resources and applications",
        "Web technologies implement client server architectures with protocols",
        "Algorithm complexity analysis determines computational feasibility",
        "Software engineering employs design patterns and architectural principles",
        "Hardware abstraction layers enable platform independence",
        "Distributed systems implement consistency and availability models",
        "Network topology determines connectivity and performance characteristics",
        "Programming language design involves syntax semantics and runtime",
        "Cryptographic protocols ensure confidentiality and authenticity",
        "Digital transformation requires integration of legacy and modern systems",
        "Emerging technologies like quantum computing challenge conventional computing"
    };

    // ====================== PHILOSOPHY SENTENCES =====================
    string philosophy_easy[20] = {
        "Philosophy asks big questions",
        "Ethics is about right and wrong",
        "Logic helps us think clearly",
        "Wisdom comes with experience",
        "Truth is important to find",
        "Knowledge is power and understanding",
        "Free will allows us choices",
        "Existence is a fundamental question",
        "Beauty is subjective and personal",
        "Justice should be fair to all",
        "Happiness is a life goal",
        "Reality can be perceived differently",
        "Morality guides our behavior",
        "Meaning comes from within",
        "Consciousness is hard to understand",
        "Peace requires understanding others",
        "Purpose drives human motivation",
        "Change is constant in life",
        "Identity shapes who we are",
        "Mind and body interact together"
    };

    string philosophy_medium[20] = {
        "Philosophy examines fundamental questions about existence",
        "Ethical systems evaluate actions based on consequences",
        "Logical reasoning follows structured argumentation patterns",
        "Epistemic knowledge requires justified true beliefs",
        "Metaphysical questions explore nature of reality",
        "Teleology suggests purposeful direction in existence",
        "Existentialism emphasizes individual freedom and responsibility",
        "Aesthetics investigates nature of beauty and art",
        "Ontology studies categories of being and substance",
        "Deontology focuses on duties and moral obligations",
        "Skepticism questions reliability of knowledge sources",
        "Phenomenology examines consciousness and perception",
        "Pragmatism evaluates truth through practical consequences",
        "Hedonism pursues pleasure as primary good",
        "Stoicism advocates virtue and emotional regulation",
        "Determinism suggests causality governs all events",
        "Nominalism questions universal abstract concepts",
        "Solipsism questions external world existence",
        "Relativism suggests truth varies by perspective",
        "Dualism posits mind body separation"
    };

    string philosophy_advanced[20] = {
        "Metaphysical inquiry examines categorical frameworks of being",
        "Normative ethics investigates principles underlying moral obligations",
        "Formal logic employs symbolic representation and inference rules",
        "Epistemology addresses justification conditions for knowledge claims",
        "Ontological arguments attempt to prove God's existence",
        "Dialectical methodology involves thesis antithesis and synthesis",
        "Phenomenological reduction suspends assumptions about external reality",
        "Aesthetic formalism evaluates art through intrinsic properties",
        "Monadology proposes indivisible substances as fundamental reality",
        "Categorical imperative universalizes maxims as moral principles",
        "Reliabilist epistemology grounds knowledge in reliable processes",
        "Intentionality characterizes consciousness as directedness toward objects",
        "Verificational theories require empirical confirmation for meaning",
        "Eudaimonia represents fulfillment through virtue actualization",
        "Apatheia describes freedom from destructive passions",
        "Causal determinism entails incompatibility with libertarian free will",
        "Universals abstract properties instantiated across particulars",
        "Cartesian doubt methodically questions certainty of knowledge",
        "Perspectivism suggests truth depends on evaluative standpoint",
        "Psychophysical interaction problems challenge mind body dualism"
    };

    // ====================== PSYCHOLOGY SENTENCES =====================
    string psychology_easy[20] = {
        "Psychology studies human behavior",
        "Emotions affect how we act",
        "Memory helps us remember things",
        "Learning happens through experience",
        "Attention focuses our thoughts",
        "Motivation drives our actions",
        "Personality shapes who we are",
        "Intelligence helps us solve problems",
        "Stress affects our mental health",
        "Dreams occur during sleep",
        "Perception shapes what we see",
        "Cognition involves thinking processes",
        "Social interaction is important",
        "Self esteem affects confidence",
        "Anxiety can feel overwhelming",
        "Depression affects mood severely",
        "Therapy helps people heal",
        "Development changes throughout life",
        "Behavior is influenced by environment",
        "Culture affects psychological processes"
    };

    string psychology_medium[20] = {
        "Cognitive psychology examines mental processes and perception",
        "Emotional intelligence involves recognizing and managing feelings",
        "Memory systems include sensory short term and long term",
        "Classical conditioning pairs stimuli with responses",
        "Operant conditioning reinforces desired behaviors",
        "Cognitive biases influence decision making processes",
        "Attachment theory explains early relationship formation",
        "Self efficacy affects performance and persistence",
        "Attribution theory explains why people behave",
        "Motivation comes from intrinsic and extrinsic sources",
        "Personality traits show consistency across situations",
        "Psychological defense mechanisms protect against anxiety",
        "Social psychology examines group and individual behavior",
        "Perception involves organizing sensory information",
        "Developmental stages mark psychological maturation",
        "Positive psychology focuses on wellbeing flourishing",
        "Flow state involves complete task engagement",
        "Neuroplasticity enables brain reorganization",
        "Resilience helps overcome adversity",
        "Mental health requires balance and coping strategies"
    };

    string psychology_advanced[20] = {
        "Cognitive neuroscience integrates brain imaging with behavioral psychology",
        "Emotional regulation involves prefrontal cortex modulation processes",
        "Memory consolidation involves long term potentiation mechanisms",
        "Behaviorism employs stimulus response frameworks exclusively",
        "Observational learning demonstrates modeling and imitation effects",
        "Metacognition involves reflection on cognitive processes",
        "Attachment styles demonstrate intergenerational transmission patterns",
        "Self determination theory proposes autonomy competence relatedness",
        "Attribution patterns reveal fundamental attribution error tendencies",
        "Expectancy theory integrates motivation and performance prediction",
        "Trait psychometrics utilize factor analysis methodology",
        "Psychodynamic theory examines unconscious mental processes",
        "Cognitive dissonance creates psychological tension resolution",
        "Gestalt psychology emphasizes holistic perceptual organization",
        "Developmental trajectories involve longitudinal assessment methods",
        "Hedonic adaptation explains wellbeing plateau phenomena",
        "Flow psychology requires challenge skill balance",
        "Synaptic plasticity underlies learning and memory consolidation",
        "Posttraumatic growth demonstrates benefit finding processes",
        "Psychological flexibility involves acceptance and valued action"
    };

    // ====================== SELF HELP SENTENCES ======================
    string selfhelp_easy[20] = {
        "Setting goals helps us improve",
        "Self care is important daily",
        "Positive thinking benefits our lives",
        "Reading books develops our minds",
        "Exercise makes us healthier",
        "Sleep is essential for health",
        "Friends provide emotional support",
        "Journaling helps process thoughts",
        "Meditation calms the mind",
        "Gratitude increases happiness",
        "Mistakes help us learn",
        "Confidence builds with practice",
        "Listening improves relationships",
        "Kindness makes others happy",
        "Time management organizes our day",
        "Patience brings better results",
        "Forgiveness releases negative emotions",
        "Purpose gives life meaning",
        "Balance creates well being",
        "Change starts within ourselves"
    };

    string selfhelp_medium[20] = {
        "Goal setting creates clear direction and accountability",
        "Self care routines support physical and mental health",
        "Positive affirmations reprogram limiting beliefs",
        "Continuous learning expands knowledge and opportunities",
        "Regular exercise improves mood and cardiovascular health",
        "Quality sleep restores cognitive and physical function",
        "Social support networks buffer against stress",
        "Reflective journaling processes emotions and experiences",
        "Mindfulness meditation reduces anxiety and increases focus",
        "Gratitude practice shifts perspective toward abundance",
        "Growth mindset views challenges as opportunities",
        "Self compassion reduces perfectionism and self criticism",
        "Active listening strengthens interpersonal connections",
        "Altruism contributes to personal fulfillment",
        "Prioritization maximizes time and energy allocation",
        "Acceptance reduces resistance to unchangeable situations",
        "Boundaries protect mental and emotional wellbeing",
        "Values alignment ensures authentic life decisions",
        "Holistic health integrates physical mental spiritual",
        "Personal development requires consistent effort"
    };

    string selfhelp_advanced[20] = {
        "SMART goal framework ensures specificity measurability and achievability",
        "Wellness optimization integrates nutrition exercise sleep",
        "Cognitive reframing transforms limiting interpretations",
        "Knowledge synthesis connects disparate learning domains",
        "Biohacking maximizes physical performance and longevity",
        "Sleep architecture optimization affects cognitive consolidation",
        "Secure attachment patterns enhance relationship quality",
        "Subliminal affirmations access implicit belief systems",
        "Metta meditation cultivates loving kindness systematically",
        "Abundance mindset removes scarcity thinking patterns",
        "Neuroplasticity leverages brain reorganization capabilities",
        "Self actualization pursues inherent potential realization",
        "Empathetic listening demonstrates genuine understanding",
        "Prosocial behavior activates reward neural pathways",
        "Eisenhower matrix categorizes importance urgency quadrants",
        "Radical acceptance embraces reality without resistance",
        "Assertiveness communication maintains authentic expression",
        "Ikigai framework aligns passion profession purpose",
        "Biopsychosocial integration addresses multidimensional health",
        "Transformational growth transcends previous limitations"
    };

    // ===================== ENVIRONMENT SENTENCES =====================
    string environment_easy[20] = {
        "Earth has limited natural resources",
        "Recycling helps protect the planet",
        "Trees clean our air",
        "Animals need habitats to survive",
        "Pollution harms our environment",
        "Water is precious and scarce",
        "Climate change is real",
        "Renewable energy helps nature",
        "Forests are important ecosystems",
        "Plastic harms ocean creatures",
        "Soil grows our food",
        "Biodiversity keeps ecosystems healthy",
        "Greenhouse gases trap heat",
        "Conservation preserves wildlife species",
        "Sustainable living helps the planet",
        "Green spaces improve our health",
        "Energy efficiency saves resources",
        "Sustainable agriculture feeds people",
        "Ocean ecosystems are fragile",
        "Future generations need our care"
    };

    string environment_medium[20] = {
        "Ecosystems maintain balance through interconnected relationships",
        "Circular economy reduces waste and resource extraction",
        "Carbon footprint measures environmental impact",
        "Habitat loss threatens species extinction",
        "Eutrophication degrades aquatic ecosystems",
        "Renewable energy transitions reduce emissions",
        "Deforestation contributes to climate change",
        "Invasive species disrupt native ecosystems",
        "Watershed management protects water quality",
        "Sustainable forestry balances conservation and use",
        "Nitrogen cycle supports agricultural productivity",
        "Marine pollution endangers aquatic biodiversity",
        "Renewable resources regenerate naturally over time",
        "Urban green spaces improve air quality",
        "Environmental impact assessment guides development",
        "Composting returns nutrients to soil",
        "Permaculture designs sustainable food systems",
        "Pollution bioaccumulates through food chains",
        "Protected areas preserve ecosystem integrity",
        "Environmental justice addresses inequitable impacts"
    };

    string environment_advanced[20] = {
        "Ecosystem services provide economic valuation frameworks",
        "Circular economy models decouple growth from resource consumption",
        "Carbon sequestration mechanisms offset anthropogenic emissions",
        "Species niche differentiation enables biodiversity maintenance",
        "Trophic cascades demonstrate predator prey dynamics",
        "Energy transition requires infrastructure and behavioral changes",
        "Anthropogenic climate forcing alters radiative balance",
        "Biodiversity loss reduces ecosystem resilience",
        "Hydrological cycling interconnects atmospheric and aquatic systems",
        "Sustainable yield maximizes resource extraction sustainability",
        "Biogeochemical cycles recycle essential nutrients",
        "Microplastics permeate aquatic and terrestrial ecosystems",
        "Renewable energy portfolios diversify power sources",
        "Urban ecology reveals anthropogenic ecosystem modifications",
        "Environmental impact assessments quantify ecological costs",
        "Soil microbiology supports nutrient cycling processes",
        "Agroecology integrates ecological principles with agriculture",
        "Persistent organic pollutants accumulate bioconcentration",
        "Ecological restoration recreates degraded ecosystem functions",
        "Anthropogenic disruption requires intervention and mitigation"
    };

    // ====================== MOTIVATION SENTENCES =====================
    string motivation_easy[20] = {
        "Dreams inspire us to achieve",
        "Success comes from hard work",
        "Believing in yourself is key",
        "Small steps lead to big goals",
        "Never give up on dreams",
        "Passion drives us forward",
        "Challenges make us stronger",
        "Others inspire our progress",
        "Failure teaches us lessons",
        "Persistence leads to success",
        "Vision guides our actions",
        "Action creates opportunities",
        "Progress motivates continued effort",
        "Inspiration comes from stories",
        "Purpose gives us direction",
        "Energy increases with practice",
        "Growth requires dedication",
        "Enthusiasm spreads to others",
        "Achievement builds confidence",
        "Inner strength overcomes obstacles"
    };

    string motivation_medium[20] = {
        "Intrinsic motivation drives sustained engagement",
        "Goal visualization enhances achievement probability",
        "Self efficacy beliefs influence performance",
        "Mastery experiences build confidence gradually",
        "Progress tracking maintains motivation and focus",
        "Meaningful purpose connects effort to values",
        "Resilience develops through adversity experiences",
        "Autonomy satisfaction increases intrinsic motivation",
        "Competence development builds self worth",
        "Relatedness supports emotional motivation",
        "Habit formation creates automatic behaviors",
        "Environmental optimization removes friction",
        "Progress celebration reinforces positive momentum",
        "Identity integration strengthens commitment",
        "Accountability partnerships increase follow through",
        "Reward systems reinforce desired behaviors",
        "Mindset shifts enable new possibilities",
        "Narrative reframing changes perspective",
        "Community support provides encouragement",
        "Personal growth becomes intrinsically rewarding"
    };

    string motivation_advanced[20] = {
        "Self determination theory integrates autonomy competence relatedness",
        "Expectancy value theory combines motivation likelihood valued outcome",
        "Growth mindset beliefs facilitate neuroplastic learning",
        "Grit perseverance predicts long term achievement",
        "Flow state optimal challenge skill balance",
        "Identity salience activates identity consistent behavior",
        "Implementation intentions specify contextual action triggers",
        "Temptation bundling pairs enjoyable with effortful activities",
        "Temporal motivation theory emphasizes deadline proximity",
        "Attribution retraining addresses helplessness and motivation",
        "Intrinsic motivation correlates with psychological need satisfaction",
        "Behavioral momentum accelerates goal achievement trajectory",
        "Precommitment devices increase follow through likelihood",
        "Narrative identity integrates life experiences coherently",
        "Extrinsic rewards undermine intrinsic motivation",
        "Goal framing prevention promotion influences approach avoidance",
        "Vicarious learning models demonstrate possibility",
        "Autonomous motivation enables self regulated persistence",
        "Emotional contagion spreads motivational energy",
        "Transcendent purpose connects individual to collective"
    };

    // ================== CRITICAL THINKING SENTENCES ==================
    string criticalthinking_easy[20] = {
        "Questions help us understand better",
        "Evidence supports strong arguments",
        "Facts differ from opinions",
        "Logical thinking avoids mistakes",
        "Bias affects our judgments",
        "Assumptions can be wrong",
        "Different perspectives matter",
        "Analysis breaks problems apart",
        "Evaluation judges information quality",
        "Inference draws conclusions carefully",
        "Reasoning follows logical patterns",
        "Fallacies weaken arguments",
        "Information sources vary in quality",
        "Context matters in interpretation",
        "Problems require systematic solving",
        "Reflection improves our thinking",
        "Skepticism questions claims",
        "Research builds knowledge",
        "Dialogue deepens understanding",
        "Wisdom comes from questioning"
    };

    string criticalthinking_medium[20] = {
        "Logical fallacies undermine argumentative validity",
        "Evidential support strengthens claims reliability",
        "Cognitive biases distort objective reasoning",
        "Confirmation bias selectively processes information",
        "Burden of proof allocates argumentative responsibility",
        "Deductive reasoning ensures logical conclusions",
        "Inductive reasoning generates probable conclusions",
        "Abductive reasoning infers best explanations",
        "Epistemological standards evaluate knowledge claims",
        "Source credibility assessment prevents misinformation",
        "Argument structure includes premises and conclusions",
        "Soundness requires validity and true premises",
        "Validity guarantees conclusion from premises",
        "Rhetoric persuades through technique",
        "Propaganda manipulates emotional responses",
        "Empiricism grounds knowledge in observation",
        "Rationalism emphasizes logical deduction",
        "Pragmatism evaluates truth through consequences",
        "Complexity analysis reveals hidden dimensions",
        "Nuance acknowledges multiple valid perspectives"
    };

    string criticalthinking_advanced[20] = {
        "Formal logic employs symbolic representation and inference rules",
        "Epistemological frameworks determine justification conditions",
        "Ontological commitments underlie theoretical assumptions",
        "Fallacious reasoning violates logical principles systematically",
        "Bayesian reasoning integrates prior probability and evidence",
        "Propositional logic demonstrates truth functional relationships",
        "Predicate logic quantifies over domains of discourse",
        "Modal logic examines necessity and possibility relationships",
        "Abductive inference generates best causal explanations",
        "Philosophical skepticism challenges certainty and knowledge",
        "Hermeneutic interpretation explores meaning and understanding",
        "Dialectical reasoning synthesizes opposing perspectives",
        "Reductionism analyzes wholes through component parts",
        "Holism examines emergent system properties",
        "Counterfactual reasoning explores conditional possibilities",
        "Heuristic analysis examines problem solving strategies",
        "Metadiscourse examines implicit argumentative assumptions",
        "Phenomenological analysis describes experiential structures",
        "Pragmatic analysis examines context dependent meaning",
        "Transcendental reasoning examines conditions enabling knowledge"
    };

    // =============== EMOTIONAL INTELLIGENCE SENTENCES ================
    string emotionalintelligence_easy[20] = {
        "Emotions are natural and valid",
        "Recognizing feelings helps us",
        "Managing emotions is important",
        "Empathy means understanding others",
        "Social skills improve relationships",
        "Self awareness builds character",
        "Emotions affect our decisions",
        "Others have feelings too",
        "Listening shows you care",
        "Respect improves interactions",
        "Expressing feelings clearly helps",
        "Conflict requires understanding",
        "Apologizing shows maturity",
        "Supporting others matters",
        "Celebrating others brings joy",
        "Emotional awareness develops over time",
        "Feedback helps us improve",
        "Patience shows emotional strength",
        "Vulnerability builds connection",
        "Emotional health is important"
    };

    string emotionalintelligence_medium[20] = {
        "Self awareness requires introspective reflection",
        "Emotional regulation manages affective responses",
        "Motivation drives goal oriented behavior",
        "Empathy recognizes others emotional states",
        "Social skills facilitate relationship quality",
        "Emotional literacy identifies feeling nuances",
        "Emotional expression communicates internal states",
        "Emotional contagion spreads affective states",
        "Perspective taking enables empathetic understanding",
        "Conflict resolution addresses interpersonal disagreements",
        "Relationship management sustains meaningful connections",
        "Emotional resilience facilitates recovery",
        "Attachment styles influence relational patterns",
        "Nonverbal communication reveals emotional information",
        "Active listening demonstrates genuine interest",
        "Emotional boundaries protect wellbeing",
        "Assertiveness expresses needs authentically",
        "Vulnerability creates authentic connection",
        "Emotional validation affirms others feelings",
        "Social awareness reads group dynamics"
    };

    string emotionalintelligence_advanced[20] = {
        "Affective neuroscience examines emotional processing mechanisms",
        "Self regulation involves prefrontal cortex modulation",
        "Intrinsic motivation correlates with emotional engagement",
        "Empathetic accuracy predicts interpersonal effectiveness",
        "Social competence integrates multiple skill dimensions",
        "Psychological flexibility enables adaptive emotional responses",
        "Emotional differentiation distinguishes nuanced feeling states",
        "Affect labeling reduces amygdala reactivity",
        "Mentalizing capacity attributes mental states accurately",
        "Perspective coordination synthesizes multiple viewpoints",
        "Conflict resolution employs collaborative problem solving",
        "Attachment security predicts relationship outcomes",
        "Microexpressions reveal suppressed emotional reactions",
        "Prosocial behavior activates reward neural systems",
        "Emotional suppression increases physiological reactivity",
        "Reappraisal strategy cognitively reframes emotion",
        "Rumination perpetuates depressive emotional states",
        "Mindfulness meditation cultivates emotion awareness",
        "Compassion fatigue requires emotional restoration",
        "Emotional intelligence predicts leadership effectiveness"
    };
    
    int level, topic;
    string sentence, input;
    
    // Display main menu for selecting difficulty level
    cout << "=========================================\n";
    cout << "          TYPING TUTOR \n";
    cout << "=========================================\n";
    cout << "1. Easy Level\n";
    cout << "2. Medium Level\n";
    cout << "3. Advanced Level\n";
    cout << "-----------------------------------------\n";
    cout << "Enter your choice (1-3): ";
    cin >> level;      // Get user's level choice
    cin.ignore();     // Clear the input buffer to avoid issues with getline later

    cout << "\n=========================================\n";
    cout << "          SELECT TOPIC \n";
    cout << "=========================================\n";
    cout << "1. History\n";
    cout << "2. Science\n";
    cout << "3. Technology\n";
    cout << "4. Philosophy\n";
    cout << "5. Psychology\n";
    cout << "6. Self Help\n";
    cout << "7. Environment\n";
    cout << "8. Motivation\n";
    cout << "9. Critical Thinking\n";
    cout << "10. Emotional Intelligence\n";
    cout << "-----------------------------------------\n";
    cout << "Enter your choice (1-10): ";
    cin >> topic;		// Get user's topic choice
    cin.ignore();		// Clear the input buffer

    srand(time(0));		// Seed the random number generator with current time
    int randomIndex = rand() % 20;		// Generate random number between 0-19

	// Check which level the user selected and assign appropriate sentence
    if (level == 1)
    {
        if (topic == 1)
            sentence = history_easy[randomIndex];
        else if (topic == 2)
            sentence = science_easy[randomIndex];
        else if (topic == 3)
            sentence = technology_easy[randomIndex];
        else if (topic == 4)
            sentence = philosophy_easy[randomIndex];
        else if (topic == 5)
            sentence = psychology_easy[randomIndex];
        else if (topic == 6)
            sentence = selfhelp_easy[randomIndex];
        else if (topic == 7)
            sentence = environment_easy[randomIndex];
        else if (topic == 8)
            sentence = motivation_easy[randomIndex];
        else if (topic == 9)
            sentence = criticalthinking_easy[randomIndex];
        else if (topic == 10)
            sentence = emotionalintelligence_easy[randomIndex];
        else
        {
            cout << "Invalid Topic!" << endl;
            return 0;
        }
    }
    else if (level == 2)
    {
        if (topic == 1)
            sentence = history_medium[randomIndex];
        else if (topic == 2)
            sentence = science_medium[randomIndex];
        else if (topic == 3)
            sentence = technology_medium[randomIndex];
        else if (topic == 4)
            sentence = philosophy_medium[randomIndex];
        else if (topic == 5)
            sentence = psychology_medium[randomIndex];
        else if (topic == 6)
            sentence = selfhelp_medium[randomIndex];
        else if (topic == 7)
            sentence = environment_medium[randomIndex];
        else if (topic == 8)
            sentence = motivation_medium[randomIndex];
        else if (topic == 9)
            sentence = criticalthinking_medium[randomIndex];
        else if (topic == 10)
            sentence = emotionalintelligence_medium[randomIndex];
        else
        {
            cout << "Invalid Topic!" << endl;
            return 0;
        }
    }
    else if (level == 3)
    {
        if (topic == 1)
            sentence = history_advanced[randomIndex];
        else if (topic == 2)
            sentence = science_advanced[randomIndex];
        else if (topic == 3)
            sentence = technology_advanced[randomIndex];
        else if (topic == 4)
            sentence = philosophy_advanced[randomIndex];
        else if (topic == 5)
            sentence = psychology_advanced[randomIndex];
        else if (topic == 6)
            sentence = selfhelp_advanced[randomIndex];
        else if (topic == 7)
            sentence = environment_advanced[randomIndex];
        else if (topic == 8)
            sentence = motivation_advanced[randomIndex];
        else if (topic == 9)
            sentence = criticalthinking_advanced[randomIndex];
        else if (topic == 10)
            sentence = emotionalintelligence_advanced[randomIndex];
        else
        {
            cout << "Invalid Topic!" << endl;
            return 0;
        }
    }
    else
    {
        cout << "Invalid Choice!" << endl;		
        return 0;		// Exit program if invalid level
    }
    
	// Display the sentence the user needs to type
    cout << "\nType the following sentence exactly:\n\n";
    cout << "\"" <<  sentence << "\"" << endl;

	// Record the start time before user types
    time_t start = time(0);

	// Get user's input (the typed sentence)
    getline(cin, input);

	// Record the end time after user finishes typing
    time_t end = time(0);

	// Calculate total time taken in seconds
    double seconds = difftime(end, start);

	// Prevent division by zero (if time is 0, set to 1 second)
    if (seconds == 0)
        seconds = 1;

    int words = 1;		// Start with 1 (every sentence has at least 1 word)

	// Count the number of words by counting spaces
    // Each space indicates a new word
    for (int i = 0; i < sentence.length(); i++)
    {
        if (sentence[i] == ' ')
            words++;
    }
    
    // Calculate Words Per Minute (WPM)
    // Formula: (total words) / (time in minutes
    double minutes = seconds / 60.0;
    double wpm = words / minutes;

    cout << "\n=========================================\n";
    cout << "RESULT\n";
    cout << "=========================================\n";

	// Check if user typed exactly the same sentence
    if (input == sentence)
        cout << "Typing Status : Correct" << endl;
    else
        cout << "Typing Status : Incorrect" << endl;

    cout << "Time Taken    : " << seconds << " seconds" << endl;
    cout << "Words Typed   : " << words << endl;
    cout << "WPM           : " << wpm << endl;

    cout << "\n------------- PERFORMANCE --------------\n";

    if (input == sentence)
    {
        if (wpm >= 40)
        {
            cout << "RATING: EXCELLENT!" << endl;
            cout << "You are a typing pro!" << endl;
        }
        else if (wpm >= 25)
        {
            cout << "RATING: GOOD JOB!" << endl;
            cout << "Keep practicing!" << endl;
        }
        else if (wpm >= 10)
        {
            cout << "RATING: NOT BAD!" << endl;
            cout << "You are improving!" << endl;
        }
        else
        {
            cout << "RATING: KEEP PRACTICING!" << endl;
            cout << "You will get better!" << endl;
        }
    }
    else		// If typing was incorrect, focus on accuracy improvement
    {
        cout << "RATING: IMPROVE ACCURACY!" << endl;
        cout << "Try typing the sentence exactly as shown." << endl;
    }

    cout << "=========================================\n";
    cout << "Thank you for using Typing Tutor System!\n";
    cout << "=========================================\n";

    return 0;		// Program executed successfully
}
